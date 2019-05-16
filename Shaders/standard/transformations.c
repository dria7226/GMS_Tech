vec3 s = vec3(1.0);
#if defined UNIFORM_BUFFER || UNIFORM_COMPRESSION
vec3 offset = vec3(0.0);
vec3 angle = vec3(0.0);
#else
vec3 offset = in_offset;
vec3 angle = in_angle;
#endif

#ifdef UNIFORM_BUFFER
vec3 camera_position = vec3(0.0);
vec3 camera_angle = vec3(0.0);
#else
vec3 camera_position = in_camera_position;
vec3 camera_angle = in_camera_angle;
#endif

#ifdef UNIFORM_BUFFER
#include "uniform_decoding.c"
#endif

#ifdef UNIFORM_COMPRESSION
//get object uniforms
#define A offset
#define B angle
#define TO_DECOMPRESS id
#define COMPRESSED_POSITION COMPRESSED_UNIFORM_POSITION
#include "decompress_float.c"
angle *= 2.0*pi/999.0;
offset *= s;
#undef A
#undef B
#undef TO_DECOMPRESS
#undef COMPRESSED_POSITION
#endif

vec3 local = in_Position;

#ifdef NORMAL_COMPRESSION
//local - extract normal and then proceed
#define A local
#define B out_Normal
#define TO_DECOMPRESS in_Position
#define COMPRESSED_POSITION COMPRESSED_NORMAL_POSITION
#include "decompress_float.c"
out_Normal = out_Normal/128.0 - vec3(1.0);
#undef A
#undef B
#undef TO_DECOMPRESS
#undef COMPRESSED_POSITION

//snap vertices
#define SMALLEST_UNIT 0.00075
local = floor(local/SMALLEST_UNIT)*SMALLEST_UNIT;

//reapply sign
local *= s;
#endif

rotate(local.xy, angle.z);
rotate(local.xz, angle.y);
rotate(local.yz, angle.x);

rotate(out_Normal.xy, angle.z);
rotate(out_Normal.xz, angle.y);
rotate(out_Normal.yz, angle.x);

//local to relative
local += offset - camera_position;

rotate(local.xy, -camera_angle.z);
rotate(local.xz, -camera_angle.y);
rotate(local.yz, -camera_angle.x);
