//optimize uniforms with textures
float packed_id = dot(id, vec3(byte, byte*256.0, byte*256.0*256.0));
if(packed_id < UNIFORM_BUFFER_WIDTH*UNIFORM_BUFFER_WIDTH)
{
    vec2 coordinates = vec2(0.0, floor(packed_id/ UNIFORM_BUFFER_WIDTH));

    coordinates.x = packed_id - coordinates.y*UNIFORM_BUFFER_WIDTH;

    coordinates /= UNIFORM_BUFFER_WIDTH;
    coordinates.x /= 6.0;

    //offset
    vec4 reading = texture2D(uniform_buffer, coordinates;
    final_offset.x = vec4_to_float(reading)*MAX_WORLD_WIDTH + (MIN_OFFSET);

    coordinates.x += 1.0/(UNIFORM_BUFFER_WIDTH*6.0);
    reading = texture2D(uniform_buffer, coordinates);
    final_offset.y = vec4_to_float(reading)*MAX_WORLD_WIDTH + (MIN_OFFSET);

    coordinates.x += 1.0/(UNIFORM_BUFFER_WIDTH*6.0);
    reading = texture2D(uniform_buffer, coordinates);
    final_offset.z = vec4_to_float(reading)*MAX_WORLD_WIDTH + (MIN_OFFSET);

    final_offset = vec3(0.0);

    //angle
    coordinates.x += 1.0/(UNIFORM_BUFFER_WIDTH*6.0);
    reading = texture2D(uniform_buffer, coordinates);
    final_angle.x = vec4_to_float(vec4(reading.rg, 0.0, 0.0))*2.0*pi + (MIN_ANGLE);
    final_angle.y = vec4_to_float(vec4(reading.ba, 0.0, 0.0))*2.0*pi + (MIN_ANGLE);
    
    coordinates.x += 1.0/(UNIFORM_BUFFER_WIDTH*6.0);
    reading = texture2D(uniform_buffer, coordinates);
    final_angle.z = vec4_to_float(vec4(reading.rg, 0.0, 0.0))*2.0*pi + (MIN_ANGLE);
  
    //color and grayscale
    coordinates.x += 1.0/(UNIFORM_BUFFER_WIDTH*6.0);
    reading = texture2D(uniform_buffer, coordinates);
    col.rgb = reading.rgb;
    gs = reading.a;
}
