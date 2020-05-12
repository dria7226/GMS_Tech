#define MRT 0
#define MIRROR_MRT 1
#define BOOLEAN_DEPTH_B 2
#define LIGHT_ACCUMULATION 3
#define EDGE 4
#define PLAYER_ONE 5
#define PLAYER_TWO 6
    #ifdef UNIFORM_BUFFER
    #undef UNIFORM_BUFFER
    #define UNIFORM_BUFFER 7
    #endif
#define OCCLUSION 8
#define OCCLUSION_DEBUG 9
#define NO_OF_SURFACES 10

#ifdef UNIFORM_BUFFER
#define UNIFORM_BUFFER_WIDTH 10.0
#endif
