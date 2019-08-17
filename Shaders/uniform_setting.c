#ifdef CACHE_UNIFORMS
#define CACHE_UNIFORM(name) name = shader_get_uniform(standard, #name);
#define GET_UNIFORM(name) name
#else
#define GET_UNIFORM(name) shader_get_uniform(standard, #name);
#endif

#define SET_UNIFORM_I(name, value) shader_set_uniform_i(GET_UNIFORM(name), value);
#define SET_UNIFORM_F(name, ...) shader_set_uniform_f(GET_UNIFORM(name), __VA_ARGS__);

#define CHANGE_SET 0
#define CHANGE_ADD 1
