SET_UNIFORM_I(vertex_mode, VERTEX_FLAT)
SET_UNIFORM_I(fragment_mode, FRAGMENT_FLAT)

//if(IS_SPLITSCREEN)
//{
//  draw_surface_part(surfaces[PLAYER_ONE],0,0,window_width*SPLITSCREEN_HORIZONTAL_RATIO, window_height/2, window_width*(1-SPLITSCREEN_HORIZONTAL_RATIO), 0);
//  draw_surface_part(surface[PLAYER_TWO],0,0, window_width*SPLITSCREEN_HORIZONTAL_RATIO, window_height/2, 0, window_height/2);
//}
//else
    draw_surface(surfaces[PLAYER_ONE],0,0);

gpu_set_blendenable(true);
gpu_set_blendmode(bm_normal);
draw_surface_ext(surfaces[BOOLEAN_DEPTH_B],0,0,0.5,1,0,0,0.5);
gpu_set_blendenable(false);

#ifdef SHOW_USE
//uses_splitscreen
#endif
