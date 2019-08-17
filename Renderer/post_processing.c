SET_UNIFORM_I(vertex_mode, VERTEX_FLAT);
SET_UNIFORM_I(fragment_mode, FRAGMENT_POST_PROCESSING)
texture_set_stage(sampler_a, surface_texture_pointers[EDGE]);

surface_set_target(FINAL_SURFACE);
draw_surface(surfaces[LIGHT_ACCUMULATION],0,0);
surface_reset_target();
