//NOTES
//account for animation as well
//account for mirrors

var identity = visibles[i];

SET_UNIFORM_F("id", PACK_32_BITS(UNIFORM_BUFFER_WIDTH*UNIFORM_BUFFER_WIDTH))

if(identity[Position] != -1)
{
  var position = identity[Position];
  SET_UNIFORM_F("offset", position.coordinates[X], position.coordinates[Y], position.coordinates[Z])
}
else
  SET_UNIFORM_F("offset", 0,0,0)

if(identity[Rotation] != -1)
{
  var rotation = identity[Rotation];
  SET_UNIFORM_F("angle", rotation.angle[ROLL], rotation.angle[PITCH], rotation.angle[YAW])
}
else
  SET_UNIFORM_F("angle", 0,0,0)

if(identity[Color] != -1)
{
  var color = identity[Color];
  SET_UNIFORM_F("color", color.channels[R], color.channels[G], color.channels[B])
}
else
  SET_UNIFORM_F("color", 0,0,0)

if(identity[Grayscale] != -1)
{
    SET_UNIFORM_F("grayscale", identity[Grayscale].value)
}
else
    SET_UNIFORM_F("grayscale", 1.0)

#include "pick_and_render_lod.c"
