attribute vec3 in_Position;		// (x,y,z)
attribute vec4 in_Color;		// (r,g,b)
attribute vec2 in_TexCoord;		// (u,v)

uniform vec3 id;
uniform sampler2D uniform_buffer;

uniform int vertex_mode;

varying float depth;
varying vec3 out_Normal;
varying vec4 out_Color;
varying vec2 out_TexCoord;

uniform vec3 camera_position;
uniform vec3 camera_angle;
uniform float zoom;
uniform float screen_ratio;

uniform vec3 offset;
uniform vec3 angle;

uniform float grayscale;
uniform vec3 color;
varying float gs;
varying vec3  col;

float packColor(vec4 color);
vec4 unpackColor(float f);
void rotate(inout vec2 point, float angle);
float vec4_to_float(vec4 color);
