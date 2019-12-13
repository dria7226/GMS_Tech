//NOTES
//- account for mirrors
//- account for animations

var lod_index = 0;

#define LOD_VAR lod_index
#define LOD_ID visibles
#include "pick_lod.c"

identity = visibles[i];

if(identity[Boolean_Group] != -1 && identity[Boolean_Group] != last_boolean_group)
{
    #include "boolean_draw_subtrahend_buffers.c"

    if(identity[Boolean_Group])
        SET_UNIFORM_I(boolean_phase, 1)
}

#undef LOD_VAR
#define LOD_VAR lod_index
#define SET_OBJECT_UNIFORMS
#include "set_uniforms.c"

#undef LOD_RENDER
#define LOD_RENDER lod_index
#include "render_lod.c"

if(identity[Boolean_Group] != -1)
{
    var next_boolean_group = -1;
    if(i < no_of_visibles-1)
    {
        next_boolean_group = visibles[i+1];
        next_boolean_group = next_boolean_group[Boolean_Group];
    }
    if(identity[Boolean_Group] != next_boolean_group)
    {
        if(identity[Boolean_Group].fill_in)
        {
            #include "boolean_fill_in.c"
        }

        if(identity[Boolean_Group])
            SET_UNIFORM_I(boolean_phase, 0)
    }
}

last_boolean_group = identity[Boolean_Group];
