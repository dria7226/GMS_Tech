//loop over lights
surface_set_target(surfaces[LIGHT_ACCUMULATION]);

SET_UNIFORM_I("vertex_mode", VERTEX_FLAT)
SET_UNIFORM_I("fragment_mode", FRAGMENT_OMNI_LIGHT)
texture_set_stage(sampler_a, surface_texture_pointers[POSITION]);

for(var i = 0; i < array_length_1D(omni_lights); i++)
{
  draw_surface(surfaces[NORMAL],0,0);
}

surface_reset_target();
