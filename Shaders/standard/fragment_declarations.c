varying float depth;
varying vec3 out_Normal;
varying vec4 out_Color;
varying vec2 out_TexCoord;

uniform vec2 a_pixel;

varying vec4 color;

uniform int fragment_mode;
uniform int boolean_phase;

uniform sampler2D boolean_depth_b_sampler;

vec4 unpackColor(float f);
void rotate(inout vec2 point, float angle);
vec4 float_to_vec4(float f);
