vec3 s = vec3(1.0);
#if defined UNIFORM_BUFFER || UNIFORM_COMPRESSION
vec3 offset = vec3(0.0);
vec3 angle = vec3(0.0);
vec3 camera_position = vec3(0.0);
vec3 camera_angle = vec3(0.0);
#else
vec3 offset = in_offset;
vec3 angle = in_angle;
vec3 camera_position = in_camera_position;
vec3 camera_angle = in_camera_angle;
#endif

#ifdef UNIFORM_BUFFER
#include "uniform_decoding.c"
#endif

#ifdef UNIFORM_COMPRESSION
//get object uniforms
offset = abs(id.xyz);
s = sign(id.xyz);
s += vec3(1.0) - abs(s);
angle = floor(offset/COMPRESSED_UNIFORM_POSITION);
offset = (offset - angle*COMPRESSED_UNIFORM_POSITION)*s;
angle *= 2.0*pi/999.0;
#endif

vec3 local = in_Position;

#ifdef NORMAL_COMPRESSION
//local - extract normal and then proceed
local = abs(local);
s = sign(in_Position);
s += vec3(1.0) - abs(s);
out_Normal = floor(local/COMPRESSED_NORMAL_POSITION);
local = local - COMPRESSED_NORMAL_POSITION*out_Normal;
out_Normal = out_Normal/128.0 - vec3(1.0);

//snap vertices
#define SMALLEST_UNIT 0.0005
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

#ifdef UNIFORM_COMPRESSION
//get camera uniforms
camera_position = abs(camera_id.xyz);
s = sign(camera_id.xyz);
s += vec3(1.0) - abs(s);
camera_angle = floor(camera_position/COMPRESSED_UNIFORM_POSITION);
camera_position = (camera_position - camera_angle*COMPRESSED_UNIFORM_POSITION)*s;
camera_angle *= 2.0*pi/999.0;
#endif

//local to relative
local += offset - camera_position;

rotate(local.xy, -camera_angle.z);
rotate(local.xz, -camera_angle.y);
rotate(local.yz, -camera_angle.x);
