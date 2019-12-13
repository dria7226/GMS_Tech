#define VERTEX_REGULAR 0
#define VERTEX_FLAT 1
#define VERTEX_OCCLUSION_DRAW 2

#define OCCLUSION_DEBUG_MODE 20

#define packColor(color) dot(color, vec4(1.0, 1.0/byte, 1.0/(byte*byte), 1.0/(byte*byte*byte))) * MAX_VIEW_DISTANCE
