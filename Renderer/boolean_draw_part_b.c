#undef LOD_VAR
#undef LOD_ID
#undef LOD_RENDER
for(var b = 0; b < no_of_booleans; b++)
{
    identity = part_b[b];

    #define SET_OBJECT_UNIFORMS
    #include "set_uniforms.c"

    var lod_b = 0;
    #define LOD_VAR lod_b
    #define LOD_ID identity
    #include "pick_lod.c"

    #define LOD_RENDER lod_b
    #include "render_lod.c"
}
