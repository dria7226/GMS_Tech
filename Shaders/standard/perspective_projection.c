#include "transformations.c"

//project
depth = length(local.xyz);

gl_Position.z = depth/far_clip*local.x;

gl_Position.xy = local.yz*near_clip;

gl_Position.x *= -screen_ratio;

gl_Position.w = local.x;