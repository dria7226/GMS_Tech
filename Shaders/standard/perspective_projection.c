#include "transformations.c"

//project
gl_Position.z = DEPTH;

gl_Position.xy = local.yz*zoom;

gl_Position.x *= -screen_ratio;

gl_Position.w = W;

depth = gl_Position.z;
