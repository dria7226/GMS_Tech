#include "Renderer/renderer_definitions.c"

#ifndef FINITE_DEPTH
#ifndef INFINITE_DEPTH
    #define INFINITE_DEPTH
#endif
#endif
#include "Shaders/depth_scaling.c"

#include "Shaders/uniform_setting.c"

#include "Options/options_definitions.c"

#include "Tag_System/tag_definitions.c"

#define PACK_32_BITS(integer) integer%256/255, floor(integer/256)%256/255, floor(integer/(256*256))/255

#define MAX_VIEW_DISTANCE 300.0
#define MIN_VIEW_DISTANCE 0.35

//2x2x2 miles
#define MAX_WORLD_WIDTH 10560.0
#define MAX_OFFSET MAX_WORLD_WIDTH/2.0
#define MIN_OFFSET -MAX_WORLD_WIDTH/2.0

#define pi 3.1415926535897932384626433832795
#define MAX_ANGLE pi
#define MIN_ANGLE -pi

#define COMPRESSED_NORMAL_POSITION 10.0
