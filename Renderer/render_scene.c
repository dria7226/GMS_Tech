surface_set_target(surfaces[MRT]);

SET_UNIFORM_I("vertex_mode", VERTEX_REGULAR)
SET_UNIFORM_I("fragment_mode", FRAGMENT_REGULAR)

texture_set_stage(uniform_sampler, surface_texture_pointers[UNIFORM_BUFFER]);
ITERATE_VISIBLES
{
    #include "mrt.c"
}

surface_reset_target();

//#include "edge.c"

//#include "collect_lights.c"

//non-shadow lights (deferred omni-lights)
//#include "lighting.c"

//shadow lights (shadow mapped spotlights)
//#include "shadowing.c"

//#include "post_processing.c"

SET_UNIFORM_I("vertex_mode", VERTEX_FLAT)
SET_UNIFORM_I("fragment_mode", FRAGMENT_FLAT)
surface_set_target(FINAL_SURFACE);
var scale = surface_info[MRT];
draw_surface_ext(surfaces[MRT],0,0, 1/scale[0], 1/scale[1],0,c_white,1.0);
surface_reset_target();

#ifdef SHOW_USE
//uses_mrt, uses_uniform_buffer, uses_visibility_culling
#endif
