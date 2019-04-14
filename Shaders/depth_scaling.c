#ifndef W_OFFSET
    #define W_OFFSET 0.0
#endif

#ifdef INFINITE_DEPTH
    #define DEPTH local.x - MIN_VIEW_DISTANCE
    #define DEPTH_REVERSE(a)
#endif

#ifdef FINITE_DEPTH
    #define DEPTH (local.x - MIN_VIEW_DISTANCE)*MAX_VIEW_DISTANCE/(MAX_VIEW_DISTANCE - MIN_VIEW_DISTANCE)

    #define DEPTH_REVERSE(a)

    #undef W_OFFSET
    #define W_OFFSET 0.0
#endif

#define W local.x + W_OFFSET
