//NOTE: B must be stored backfaced

var part_b = identity[Boolean].models;
var no_of_booleans = array_length_1d(part_b);

SET_UNIFORM_I(fragment_mode, FRAGMENT_DEPTH)
gpu_set_cullmode(cull_clockwise);

surface_reset_target();
surface_set_target(surfaces[BOOLEAN_FRONT_B]);
draw_clear(c_black);
//draw front of part B
#include "boolean_draw_part_b.c"
surface_reset_target();

// identity = visibles[i];
// #define SET_OBJECT_UNIFORMS
// #include "set_uniforms.c"
//
// #undef LOD_VAR
// #undef LOD_ID
// #define LOD_VAR lod_index
// #define LOD_ID identity
// #include "pick_lod.c"
//
// if(identity[Boolean].fill_in)
// {
//     surface_set_target(surfaces[BOOLEAN_BACK_A]);
//     //draw back of A
//     #undef LOD_RENDER
//     #define LOD_RENDER min(lod_index + 1, 2)
//     #include "render_lod.c"
//     surface_reset_target();
// }

//reset culling
gpu_set_cullmode(cull_counterclockwise);

surface_set_target(surfaces[BOOLEAN_BACK_B]);
//draw back of B
draw_clear(c_black);
#include "boolean_draw_part_b.c"
surface_reset_target();

SET_UNIFORM_I(fragment_mode, FRAGMENT_MRT)
surface_set_target(surfaces[MRT]);
//assign boolean surfaces to samplers
//texture_set_stage(boolean_front_b_sampler, surface_get_texture(surfaces[BOOLEAN_FRONT_B]));
//texture_set_stage(boolean_back_a_sampler, surface_get_texture(surfaces[BOOLEAN_BACK_A]));
//texture_set_stage(boolean_back_b_sampler, surface_get_texture(surfaces[BOOLEAN_BACK_B]));

// //draw front of A
//#include "boolean_phase_c_1.c"

// if(identity[Boolean].fill_in)
// {
//     //fill in
       // draw B on stencil
//     #include "boolean_draw_part_b.c"
// }

//reset submode
#ifdef SHOW_USE
//uses_boolean, uses_lod, uses_vbo_tag, uses_mrt
#endif
