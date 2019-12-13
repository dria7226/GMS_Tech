//     surface_set_target(surfaces[BOOLEAN_BACK_A]);
//     //draw back of A
//     #undef LOD_RENDER
//     #define LOD_RENDER min(lod_index + 1, 2)
//     #include "boolean_draw_minuends.c"
//     surface_reset_target();

//     //fill in
       // draw B on stencil
//     #include "boolean_draw_subtrahends.c"
