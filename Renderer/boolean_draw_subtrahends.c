#undef LOD_VAR
#undef LOD_RENDER
#undef LOD_ID
#define LOD_ID identity
for(var b = 0; b < no_of_subtrahends; b++)
{
    identity = subtrahends[b];

    #define SET_OBJECT_UNIFORMS
    #include "set_uniforms.c"

    var lod_b = 0;
    #define LOD_VAR lod_b
    #include "pick_lod.c"

    #define LOD_RENDER lod_b
    #include "render_lod.c"
}
