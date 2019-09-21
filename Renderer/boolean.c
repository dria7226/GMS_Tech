//NOTE: B must be stored backfaced

var part_b = identity[Boolean].models;
var no_of_booleans = array_length_1D(part_b);

//draw front and back of part B
#include "boolean_phase_a_1.c"

identity = visibles[i];
#define SET_OBJECT_UNIFORMS
#include "set_uniforms.c"

#define LOD_VAR lod_index
#define LOD_ID identity
#include "pick_lod.c"

if(identity[Boolean].fill_in)
{
    //draw back of A
    #include "boolean_phase_a_2.c"
}

//draw front of A
#include "boolean_phase_b_1.c"

if(identity[Boolean].fill_in)
{
    //fill in
    #include "boolean_phase_b_2.c"
}

//reset submode
//...
#ifdef SHOW_USE
//uses_boolean, uses_lod, uses_vbo_tag, uses_mrt
#endif
