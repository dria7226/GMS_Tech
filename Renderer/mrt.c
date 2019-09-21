//NOTES
//- account for mirrors
//- account for animations

var lod_index = 0;

#define LOD_VAR lod_index
#define LOD_ID visibles
#include "pick_lod.c"

identity = visibles[i];

//if(identity[BOOLEAN] != -1)
//{
//    #include "boolean.c"
//}
//else
{
    #define SET_OBJECT_UNIFORMS
    #include "set_uniforms.c"

    #define LOD_RENDER lod_index
    #include "render_lod.c"
}
