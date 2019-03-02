//get positions and radius
var camera = GET_CAMERA_POSITION;
var object = GET_OBJECT_POSITION;

var object_radius = GET_OBJECT_RADIUS;

//calculate relative position and distance
var relative_position = [ object.X - camera.X,
                          object.Y - camera.Y,
                          object.Z - camera.Z];

for(var i = 0; i < 3; i++) relative_position[i] *= relative_position[i];

var distance = sqrt(relative_position[0] + relative_position[1] + relative_position[2]);

//cull far first
if((distance - object_radius) > far_clip) continue;

//if its a group compare camera overlap
if(is_group && distance < object_radius)
{
  //add_group_to_hierarchy
  //or leaves to visible models
  continue;
}

//transform radius to angle
var object_radius = object_radius/distance;???

//cull according to frustum sides
