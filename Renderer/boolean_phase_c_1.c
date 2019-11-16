SET_UNIFORM_I(boolean_phase, A)
#undef LOD_RENDER
#define LOD_RENDER lod_index
#include "render_lod.c"
    // if B goes through, discard
    // if inside B discard and mark stencil
    // else, draw
