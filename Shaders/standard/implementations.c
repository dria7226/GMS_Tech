void rotate(inout vec2 point, float angle)
{
  float X = cos(angle)*point.x - sin(angle)*point.y;
  point.y = cos(angle)*point.y + sin(angle)*point.x;
  point.x = X;
}

float packColor(vec4 color)
{
    return dot( color, vec4(1.0, 1.0/byte, 1.0/(byte*byte), 1.0/(byte*byte*byte)) );
}

vec4 unpackColor(float f)
{
  f /= MAX_VIEW_DISTANCE;
  vec4 enc = f * vec4(1.0, byte, byte*byte, byte*byte*byte);
  enc = fract(enc);
  enc.rgb -= enc.gba/vec3(byte);
  return enc;
}

//pack_id() dot(id, vec3(byte, byte*256.0, byte*256.0*256.0))

//percentage to partial percentages
vec4 float_to_vec4(float f)
{
    float max_value = byte/256.0;
    float r = floor(f/max_value);
    f -= r*max_value;
    max_value /= 256.0;
    float g = floor(f/max_value);
    f -= g*max_value;
    max_value /= 256.0;
    float b = floor(f/max_value);
    f -= b*max_value;
    max_value /= byte;
    float a = floor(f/max_value);

    return vec4(r,g,b,a);
}

//partial percentages to percentage
float vec4_to_float(vec4 color)
{
    return dot(vec3(color.r*byte, color.g*byte, color.b*byte  + color.a), vec3(1.0)/vec3(256.0, 256.0*256.0, 256.0*256.0*256.0));
}
