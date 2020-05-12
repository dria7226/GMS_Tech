//NOTES
//- account for mirrors
//- account for animations

var lod_index = 0;

#define LOD_VAR lod_index
#include "pick_lod.c"

identity = visibles[i];

#include "boolean_pre_draw.c"

identity = visibles[i];

if(identity[VBO] != -1)
{
    #define SET_OBJECT_UNIFORMS
    #include "set_uniforms.c"

    #undef LOD_VAR
    #define LOD_VAR lod_index
    #include "pick_lod.c"

    vertex_submit(identity[VBO].lod[LOD_VAR], pr_trianglelist, 0);
}

#include "boolean_post_draw.c"

last_boolean_group = identity[Boolean_Group];
