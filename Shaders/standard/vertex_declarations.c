attribute vec3 in_Position;		// (x,y,z)
attribute vec4 in_Color;		// (r,g,b)
attribute vec2 in_TexCoord;		// (u,v)

#ifdef UNIFORM_BUFFER
uniform sampler2D uniform_buffer;
uniform vec4 camera_id;
#endif

uniform int vertex_mode;

uniform vec4 id;

#ifndef UNIFORM_BUFFER
uniform vec3 in_camera_position;
uniform vec3 in_camera_angle;
uniform float zoom;
#endif

uniform float screen_ratio;

#if defined UNIFORM_BUFFER || UNIFORM_COMPRESSION
#else
uniform vec3 in_offset;
uniform vec3 in_angle;
uniform vec3 in_color;
uniform float in_grayscale;
#endif

varying float grayscale;
varying vec3  color;

varying float depth;
varying vec3 out_Normal;
varying vec4 out_Color;
varying vec2 out_TexCoord;

float packColor(vec4 color);
vec4 unpackColor(float f);
void rotate(inout vec2 point, float angle);
float vec4_to_float(vec4 color);
