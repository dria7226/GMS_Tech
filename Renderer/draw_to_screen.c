SET_UNIFORM_I("vertex_mode", VERTEX_FLAT)
SET_UNIFORM_I("fragment_mode", FRAGMENT_UNIFORM_ENCODING)
surface_set_target(surfaces[PLAYER_ONE]);

draw_rectangle(0,0, 3,3,false);

surface_reset_target();

SET_UNIFORM_I("fragment_mode", FRAGMENT_FLAT)

//if(IS_SPLITSCREEN)
//{
//  draw_surface_part(surfaces[PLAYER_ONE],0,0,window_width*SPLITSCREEN_HORIZONTAL_RATIO, window_height/2, window_width*(1-SPLITSCREEN_HORIZONTAL_RATIO), 0);
//  draw_surface_part(surface[PLAYER_TWO],0,0, window_width*SPLITSCREEN_HORIZONTAL_RATIO, window_height/2, 0, window_height/2);
//}
//else
    draw_surface(surfaces[PLAYER_ONE],0,0);

#ifdef SHOW_USE
//uses_splitscreen
#endif
