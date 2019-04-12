varying float depth;
varying vec3 out_Normal;
varying vec4 out_Color;
varying vec2 out_TexCoord;

uniform vec3 pass_offset;
uniform vec3 pass_angle;
uniform vec3 pass_scale;

uniform vec2 a_pixel;
uniform sampler2D uniform_buffer;

varying float gs;
varying vec3 col;

uniform int fragment_mode;

float packColor(vec4 color);
vec4 unpackColor(float f);
void rotate(inout vec2 point, float angle);
vec4 float_to_vec4(float f);
