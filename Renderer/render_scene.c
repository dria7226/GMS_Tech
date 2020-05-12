surface_set_target(surfaces[MRT]);
gpu_set_tex_filter(true);

SET_UNIFORM_I(vertex_mode, VERTEX_REGULAR)
SET_UNIFORM_I(fragment_mode, FRAGMENT_MRT)

#ifdef UNIFORM_BUFFER
texture_set_stage(uniform_sampler, surface_get_texture(surfaces[UNIFORM_BUFFER]));
#endif

var last_boolean_group = -1;
ITERATE_VISIBLES
{
    #include "mrt.c"
}

gpu_set_tex_filter(false);
surface_reset_target();

//#include "collect_lights.c"

//non-shadow lights (deferred light volumes)
//#include "lighting.c"

//shadow lights (shadow mapped spotlights)
//#include "shadowing.c"

//#include "post_processing.c"

SET_UNIFORM_I(vertex_mode, VERTEX_FLAT)
SET_UNIFORM_I(fragment_mode, FRAGMENT_FLAT)
surface_set_target(FINAL_SURFACE);
var scale = surface_info[MRT];
draw_surface_ext(surfaces[MRT],0,0, 1/scale[0], 1/scale[1],0,c_white,1.0);
surface_reset_target();

#ifdef SHOW_USE
//uses_mrt, uses_uniform_buffer, uses_visibility_culling, uses_uniform_compression
#endif
