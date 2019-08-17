#undef ID_UNIFORM
#ifdef SET_OBJECT_UNIFORMS
#define ID_UNIFORM object_id
#endif
#ifdef SET_CAMERA_UNIFORMS
#define ID_UNIFORM camera_id
#endif

#ifdef UNIFORM_COMPRESSION
#ifdef SET_OBJECT_UNIFORMS
if(identity[Cached_ID] == -1) continue;
#endif
#endif

#if defined UNIFORM_BUFFER || UNIFORM_COMPRESSION
#ifdef SET_OBJECT_UNIFORMS
SET_UNIFORM_F(ID_UNIFORM, identity[Cached_ID].cache[0], identity[Cached_ID].cache[1], identity[Cached_ID].cache[2], identity[Cached_ID].cache[3])
#endif
#endif

#ifdef SET_CAMERA_UNIFORMS
var position = identity[Position];
SET_UNIFORM_F(in_camera_position, position.coordinates[X], position.coordinates[Y], position.coordinates[Z])
var rotation = identity[Rotation];
SET_UNIFORM_F(in_camera_angle, rotation.axes[ROLL], rotation.axes[PITCH], rotation.axes[YAW])
#endif

#ifndef UNIFORM_BUFFER
#ifndef UNIFORM_COMPRESSION

#ifdef SET_OBJECT_UNIFORMS

var offset = default_offset;
position = identity[Position];
if(position != -1)
    offset = position.coordinates;

var angle = default_angle;
rotation = identity[Rotation];
if(rotation != -1)
    angle = rotation.axes;

var color = default_color;
var color_and_gs = identity[Color];
if(color_and_gs != -1)
    color = color_and_gs.channels;

SET_UNIFORM_F(in_offset, offset[X], offset[Y], offset[Z])
SET_UNIFORM_F(in_angle, angle[ROLL], angle[PITCH], angle[YAW])
SET_UNIFORM_F(in_color, color[R], color[G], color[B], color[GS])
#endif

#endif
#endif

#ifdef SET_CAMERA_UNIFORMS
#ifndef UNIFORM_COMPRESSION
SET_UNIFORM_F(zoom, identity[Camera].zoom)
#endif
#endif

#undef SET_OBJECT_UNIFORMS
#undef SET_CAMERA_UNIFORMS
#undef ID_UNIFORM

#ifdef SHOW_USE
//uses_uniform_buffer, uses_uniform_compression
#endif
