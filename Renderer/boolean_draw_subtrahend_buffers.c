//NOTE: B must be stored backfaced

var subtrahends = identity[Boolean_Group].subtrahends;
var no_of_subtrahends = array_length_1d(subtrahends);

SET_UNIFORM_I(fragment_mode, FRAGMENT_DEPTH)
gpu_set_cullmode(cull_clockwise);

surface_reset_target();
surface_set_target(surfaces[BOOLEAN_FRONT_B]);
draw_clear(c_black);
//draw front of part B
#include "boolean_draw_subtrahends.c"
surface_reset_target();

//reset culling
gpu_set_cullmode(cull_counterclockwise);

surface_set_target(surfaces[BOOLEAN_BACK_B]);
//draw back of B
draw_clear(c_black);
#include "boolean_draw_subtrahends.c"
surface_reset_target();

identity = visibles[i];

SET_UNIFORM_I(fragment_mode, FRAGMENT_MRT)
surface_set_target(surfaces[MRT]);
texture_set_stage(boolean_front_b_sampler, surface_get_texture(surfaces[BOOLEAN_FRONT_B]));
texture_set_stage(boolean_back_b_sampler, surface_get_texture(surfaces[BOOLEAN_BACK_B]));
