import bpy
import os
import mathutils, math ,struct
import shutil
import bpy_extras

class Property:
    apply_modifiers = True
    apply_transforms = True
    export_colors = True
    export_uvs = True
    flip_uvs = True

properties = Property()

#properties.apply_modifiers = False

model_within_bounds = True

def writeVertex(mesh, face, i, file):
    index = face.vertices[i]
    vert = mesh.vertices[index]

    if abs(vert.co.x) > 100 or abs(vert.co.y) > 100 or abs(vert.co.z) > 100:
        model_within_bounds = False

    if face.use_smooth:
        nx = vert.normal.x
        ny = vert.normal.y
        nz = vert.normal.z
    else:
        nx = face.normal.x
        ny = face.normal.y
        nz = face.normal.z

    nx = (nx + 1)*128*100
    ny = (ny + 1)*128*100
    nz = (nz + 1)*128*100

    print("vx: ", vert.co.x,"vy: ", vert.co.y,"vz: ", vert.co.z)

    print("nx: ", nx,"ny: ", ny,"nz: ", nz)

    print("x: ", vert.co.x + math.copysign(nx, vert.co.x),"y: ", vert.co.y + math.copysign(ny, vert.co.y),"z: ", vert.co.z + math.copysign(nz, vert.co.z))

    #put position and normal together
    file.write(struct.pack('<fff',vert.co.x + math.copysign(nx, vert.co.x), vert.co.y + math.copysign(ny, vert.co.y), vert.co.z + math.copysign(nz, vert.co.z)))

    if properties.export_colors:
        if len(mesh.vertex_colors) > 0:
            faceCol = mesh.tessface_vertex_colors.active.data[face.index]

            face_colors = [faceCol.color1, faceCol.color2, faceCol.color3, faceCol.color4]
            col = face_colors[i]

            file.write(struct.pack('<BBBB', int(col[0] * 255.0), int(col[1] * 255.0), int(col[2] * 255.0), 255))
        else:
            file.write(struct.pack('<BBBB', 255, 255, 255, 255))

    if properties.export_uvs:
        if len(mesh.uv_textures) > 0:
            faceUV = mesh.tessface_uv_textures.active.data[face.index]
            if properties.flip_uvs:
                file.write(struct.pack('<ff', faceUV.uv[i][0], 1 - faceUV.uv[i][1]))
            else:
                file.write(struct.pack('<ff', faceUV.uv[i][0], faceUV.uv[i][1]))
        else:
            file.write(struct.pack('<ff', 0, 0))

def exportMesh(mesh, file):
    mesh.calc_normals()
    mesh.calc_tessface()

    for face in mesh.tessfaces:
        if len(face.vertices) >= 3:
            writeVertex(mesh, face, 0, file)
            writeVertex(mesh, face, 1, file)
            writeVertex(mesh, face, 2, file)
        if len(face.vertices) == 4:
            writeVertex(mesh, face, 2, file)
            writeVertex(mesh, face, 3, file)
            writeVertex(mesh, face, 0, file)

def do_export(filepath):
    file = open(filepath, "wb")

    LOOPOBS = bpy.context.visible_objects

    for ob in LOOPOBS:
        if ob.type == 'MESH':#Only export meshes
            mesh = ob.to_mesh(bpy.context.scene, properties.apply_modifiers, 'PREVIEW', True)#Make a mesh copy and tesselate
            if properties.apply_transforms:
                mesh.transform(ob.matrix_world)

            exportMesh(mesh, file)

            bpy.data.meshes.remove(mesh)
	#End Selection Loop

    file.flush()
    file.close()

    return True

print("---Starting model compilation---")
total = 0
#loop over every folder, except the "Deprecated" folder
for subdir, dirs, files in os.walk('E:\Detective_Assets\Blender'):
    if subdir.endswith('Deprecated'):
        continue

    for file in files:
        #do only .blends
        if not file.endswith('.blend'):
            continue

        #compare "last modified" dates
        needs_update = False

        #if equivalent doesnt exist, then needs update
        equivalent_folder= subdir.replace('Blender','Compiled_Assets')

        if not os.path.exists(equivalent_folder):
            os.makedirs(equivalent_folder)
            needs_update = True

        equivalent_path = os.path.join(equivalent_folder, file.replace('.blend','.dat'))

        if not os.access(equivalent_path, os.F_OK):
            needs_update = True
        else:
            original_mtime = os.path.getmtime(subdir)
            equivalent_time = os.path.getmtime(equivalent_path)
            if original_mtime > equivalent_time:
                needs_update = True

        if needs_update:
            print(equivalent_path)
            #open file in blender
            bpy.ops.wm.open_mainfile(filepath=os.path.join(subdir, file))

            model_within_bounds = True

            do_export(equivalent_path)

            if not model_within_bounds:
                print("Model ",file," is out of bounds")

            total += 1

print("Total models updated: ", total)
print("---Model compilation ended---")
