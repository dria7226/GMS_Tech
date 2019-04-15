SET_UNIFORM_I("vertex_mode", VERTEX_FLAT)
SET_UNIFORM_I("fragment_mode", FRAGMENT_FLAT)
surface_set_target(surfaces[PLAYER_ONE]);

draw_surface_stretched(surfaces[UNIFORM_BUFFER],0,0, UNIFORM_BUFFER_WIDTH*6*10,UNIFORM_BUFFER_WIDTH*10);

surface_reset_target();

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
