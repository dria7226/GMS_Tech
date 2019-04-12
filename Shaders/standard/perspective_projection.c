#include "transformations.c"

//project
depth = (local.x - MIN_VIEW_DISTANCE)/(MAX_VIEW_DISTANCE - MIN_VIEW_DISTANCE)*MAX_VIEW_DISTANCE;

gl_Position.z = depth;

depth /= local.x;

gl_Position.xy = local.yz*zoom;

gl_Position.x *= -screen_ratio;

gl_Position.w = local.x;
