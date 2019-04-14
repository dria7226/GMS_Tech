vec3 final_offset = offset;
vec3 final_angle = angle;

#include "uniform_decoding.c"

//local - extract normal and then proceed
vec3 local = abs(in_Position);
vec3 sign = in_Position/local;
sign += vec3(1.0) - abs(sign);
out_Normal = floor(local/COMPRESSED_NORMAL_POSITION);
local = (local - COMPRESSED_NORMAL_POSITION*out_Normal);
out_Normal = out_Normal/128.0 - vec3(1.0);

//snap vertices
#define SMALLEST_UNIT 0.0005
local = floor(local/SMALLEST_UNIT)*SMALLEST_UNIT;

//reapply sign
local *= sign;

rotate(local.xy, final_angle.z);
rotate(local.xz, final_angle.y);
rotate(local.yz, final_angle.x);

rotate(out_Normal.xy, final_angle.z);
rotate(out_Normal.xz, final_angle.y);
rotate(out_Normal.yz, final_angle.x);

//local to relative
local += final_offset - camera_position;

rotate(local.xy, -camera_angle.z);
rotate(local.xz, -camera_angle.y);
rotate(local.yz, -camera_angle.x);
