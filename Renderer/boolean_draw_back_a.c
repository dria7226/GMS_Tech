//draw back of A
SET_UNIFORM_I(vertex_mode, VERTEX_FLAT)
SET_UNIFORM_I(fragment_mode, FRAGMENT_FLAT)

surface_set_target(surfaces[BOOLEAN_BACK_A]);
draw_clear(c_black);

SET_UNIFORM_I(vertex_mode, VERTEX_REGULAR)
SET_UNIFORM_I(fragment_mode, FRAGMENT_DEPTH)
texture_set_stage(boolean_front_a_sampler, surface_get_texture(surfaces[MRT]));
#undef LOD_RENDER
#define LOD_RENDER min(lod_index + 1, 2)
for(var a = fill_in_start_index; a <= i; a++)
{
    identity = visibles[a];

    #define SET_OBJECT_UNIFORMS
    #include "set_uniforms.c"

    #undef LOD_VAR
    #define LOD_VAR lod_index
    #include "pick_lod.c"

    if(identity[VBO] != -1)
    {
        vertex_submit(identity[VBO].lod[LOD_VAR], pr_trianglelist, 0);
    }
}
surface_reset_target();
SET_UNIFORM_I(fragment_mode, FRAGMENT_MRT)

texture_set_stage(boolean_back_a_sampler, surface_get_texture(surfaces[BOOLEAN_BACK_A]));
