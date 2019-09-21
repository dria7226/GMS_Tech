surface_set_target(surfaces[BOOLEAN_MRT]);
//draw_clear();
gpu_set_cullmode(cull_noculling);
//set submode
//draw all B on boolean MRT(min/max)
#include "boolean_draw_part_b.c"
