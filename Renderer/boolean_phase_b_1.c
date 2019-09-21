surface_set_target(surfaces[MRT]);
//assign boolean MRT to sampler
texture_set_stage(boolean_sampler, surface_get_texture(surfaces[BOOLEAN_MRT]));
//reset culling
gpu_set_cullmode(cull_counterclockwise);
//set submode
#define LOD_RENDER lod_index
#include "render_lod.c"
    // if B goes through, discard
    // if inside B discard and mark stencil
    // else, draw
