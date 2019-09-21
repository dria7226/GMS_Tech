//cull the front
gpu_set_cullmode(cull_clockwise);
//set submode
#define LOD_RENDER min(lod_index + 1, 2)
#include "render_lod.c"
