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
        if(identity[Boolean_Group].boolean_type)
        {
            //BOOLEAN_CUTOUT

            //draw fill in
            //var fill_in_to_draw = identity[Boolean_Group].fill_in;
            //         if(!fill_in_to_draw)
            //             fill_in_to_draw = identity[Boolean_Group].subtrahends;
            //
            //         var no_of_fill_ins = array_length_1d(fill_in_to_draw);
            //         for(var i = 0; i < no_of_fill_ins; i++)
            //         {
            //             identity = fill_in_to_draw[i];
            //
            //             if(identity[VBO] != -1)
            //             {
            //                 #define SET_OBJECT_UNIFORMS
            //                 #include "set_uniforms.c"
            //
            //                 #undef LOD_VAR
            //                 #define LOD_VAR lod_index
            //                 #include "pick_lod.c"
            //
            //                 vertex_submit(identity[VBO].lod[LOD_VAR], pr_trianglelist, 0);
            //             }
                //     }
        }
        else
        {
            //BOOLEAN_CARVE
            gpu_set_zfunc(cmpfunc_greaterequal);
            SET_UNIFORM_I(boolean_phase, 3)

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

            gpu_set_zfunc(cmpfunc_lessequal);
        }

        SET_UNIFORM_I(boolean_phase, 0)
    }
}
