if(identity[Boolean_Group] != -1 && identity[Boolean_Group] != last_boolean_group && identity[Boolean_Group].boolean_type == BOOLEAN_CUTOUT)
{
    var subtrahends = identity[Boolean_Group].subtrahends;
    var no_of_subtrahends = array_length_1d(subtrahends);

    surface_reset_target();
    #include "boolean_draw_subtrahend_buffers.c"

    SET_UNIFORM_I(fragment_mode, FRAGMENT_MRT)
    surface_set_target(surfaces[MRT]);

    SET_UNIFORM_I(boolean_phase, 2)
}
