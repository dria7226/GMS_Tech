//NOTES
//- account for mirrors
//- account for animations
//- account for boolean rendering

var lod_index = 0;

#define LOD_VAR lod_index
#define LOD_ID visibles
#include "pick_lod.c"

identity = visibles[i];

if(identity[Boolean] != -1)
{
    #include "boolean.c"
}
else
{
    #define SET_OBJECT_UNIFORMS
    #include "set_uniforms.c"

    #undef LOD_RENDER
    #define LOD_RENDER lod_index
    #include "render_lod.c"
}
