SET_UNIFORM_I(boolean_phase, C_1)
#undef LOD_RENDER
#define LOD_RENDER lod_index
#include "render_lod.c"
    // if B goes through, discard
    // if inside B discard and mark stencil
    // else, draw
