CACHE_UNIFORM(in_camera_position)
CACHE_UNIFORM(in_camera_angle)
CACHE_UNIFORM(zoom)

CACHE_UNIFORM(vertex_mode)
CACHE_UNIFORM(fragment_mode)
CACHE_UNIFORM(boolean_phase)
CACHE_UNIFORM(a_pixel)
CACHE_UNIFORM(screen_ratio)
#ifdef UNIFORM_BUFFER
uniform_sampler = shader_get_sampler_index(standard, "uniform_buffer");
CACHE_UNIFORM(camera_id)
#endif

boolean_front_b_sampler = shader_get_sampler_index(standard, "boolean_front_b_sampler");
boolean_back_b_sampler = shader_get_sampler_index(standard, "boolean_back_b_sampler");
boolean_back_a_sampler = shader_get_sampler_index(standard, "boolean_back_a_sampler");

CACHE_UNIFORM(object_id)
#if defined UNIFORM_BUFFER || UNIFORM_COMPRESSION
#else
CACHE_UNIFORM(in_offset)
CACHE_UNIFORM(in_angle)
CACHE_UNIFORM(in_color)
#endif
