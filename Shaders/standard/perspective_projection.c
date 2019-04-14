#include "transformations.c"

//project
depth = DEPTH;

gl_Position.z = depth;

depth /= W;

gl_Position.xy = local.yz*zoom;

gl_Position.x *= -screen_ratio;

gl_Position.w = W;
