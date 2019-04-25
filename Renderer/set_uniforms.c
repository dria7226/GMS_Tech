#undef ID_UNIFORM
#ifdef SET_OBJECT_UNIFORMS
#define ID_UNIFORM "id"
#endif
#ifdef SET_CAMERA_UNIFORMS
#define ID_UNIFORM "camera_id"
#endif

#ifdef UNIFORM_COMPRESSION
#ifdef SET_OBJECT_UNIFORMS
if(identity[Cached_ID] == -1) continue;
#endif
#endif

#if defined UNIFORM_BUFFER || UNIFORM_COMPRESSION
SET_UNIFORM_F(ID_UNIFORM, identity[Cached_ID].cache[0], identity[Cached_ID].cache[1], identity[Cached_ID].cache[2], identity[Cached_ID].cache[3])
#endif

#ifndef UNIFORM_BUFFER
#ifndef UNIFORM_COMPRESSION

#ifdef SET_CAMERA_UNIFORMS
var position = identity[Position];
SET_UNIFORM_F("in_camera_position", position.coordinates[X], position.coordinates[Y], position.coordinates[Z])
var rotation = identity[Rotation];
SET_UNIFORM_F("in_camera_angle", rotation.angle[ROLL], rotation.angle[PITCH], rotation.angle[YAW])
#endif

#ifdef SET_OBJECT_UNIFORMS
if(identity[Position] != -1)
{
  var position = identity[Position];
  SET_UNIFORM_F("in_offset", position.coordinates[X], position.coordinates[Y], position.coordinates[Z])
}
else
  SET_UNIFORM_F("in_offset", 0,0,0)

if(identity[Rotation] != -1)
{
  var rotation = identity[Rotation];
  SET_UNIFORM_F("in_angle", rotation.angle[ROLL], rotation.angle[PITCH], rotation.angle[YAW])
}
else
  SET_UNIFORM_F("in_angle", 0,0,0)

if(identity[Color] != -1)
{
  var color = identity[Color];
  SET_UNIFORM_F("in_color", color.channels[R], color.channels[G], color.channels[B])
}
else
  SET_UNIFORM_F("in_color", 0,0,0)

if(identity[Grayscale] != -1)
{
    SET_UNIFORM_F("in_grayscale", identity[Grayscale].value)
}
else
    SET_UNIFORM_F("in_grayscale", 1.0)
#endif

#endif
#endif

#ifdef SET_CAMERA_UNIFORMS
#ifndef UNIFORM_COMPRESSION
SET_UNIFORM_F("zoom", identity[Camera].zoom)
#endif
#endif

#undef SET_OBJECT_UNIFORMS
#undef SET_CAMERA_UNIFORMS
#undef ID_UNIFORM

#ifdef SHOW_USE
//uses_uniform_buffer, uses_uniform_compression
#endif
