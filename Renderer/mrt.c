//NOTES
//- account for mirrors
//- account for animations

var identity = visibles[i];

SET_UNIFORM_F("id", PACK_32_BITS(identity[INDEX]))

#include "pick_and_render_lod.c"

#ifdef SHOW_USE
//uses_uniform_buffer
#endif
