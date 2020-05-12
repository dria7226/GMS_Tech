for(var b = 0; b < no_of_subtrahends; b++)
{
    identity = subtrahends[b];

    #define SET_OBJECT_UNIFORMS
    #include "set_uniforms.c"

    var lod_b = 0;
    #undef LOD_VAR
    #define LOD_VAR lod_b
    #include "pick_lod.c"

    if(identity[VBO] != -1)
    {
        vertex_submit(identity[VBO].lod[LOD_VAR], pr_trianglelist, 0);
    }
}
