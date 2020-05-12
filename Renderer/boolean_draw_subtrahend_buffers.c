SET_UNIFORM_I(vertex_mode, VERTEX_FLAT)
SET_UNIFORM_I(fragment_mode, FRAGMENT_FLAT)
surface_set_target(surfaces[BOOLEAN_DEPTH_B]);
draw_clear(c_black);
SET_UNIFORM_I(vertex_mode, VERTEX_REGULAR)
SET_UNIFORM_I(fragment_mode, FRAGMENT_DEPTH)
gpu_set_zfunc(cmpfunc_always);
gpu_set_cullmode(cull_noculling);
SET_UNIFORM_I(boolean_phase, 1)
#include "boolean_draw_subtrahends.c"
surface_reset_target();
gpu_set_cullmode(cull_counterclockwise);
gpu_set_zfunc(cmpfunc_lessequal);

identity = visibles[i];

texture_set_stage(boolean_depth_b_sampler, surface_get_texture(surfaces[BOOLEAN_DEPTH_B]));
