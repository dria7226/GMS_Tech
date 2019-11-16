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

#define PACK_32_BITS(integer) integer%256/255, floor(integer/256)%256/255, floor(integer/256/256)/255

#define MAX_VIEW_DISTANCE 300.0
#define MIN_VIEW_DISTANCE 0.16

#include "Models/model_definitions.c"
