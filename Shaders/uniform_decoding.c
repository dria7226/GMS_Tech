//optimize uniforms with textures
if(id.y <= 1.0)
{
    vec2 coordinates = id.xy;

    //offset
    vec4 reading = texture2D(uniform_buffer, coordinates);
    offset.x = vec4_to_float(reading)*MAX_WORLD_WIDTH + (MIN_OFFSET);
    if(dot(reading,vec4(1.0)) == 0.0) final_offset.x = 10.0;

    coordinates.x += 1.0/(UNIFORM_BUFFER_WIDTH*6.0);
    reading = texture2D(uniform_buffer, coordinates);
    offset.y = vec4_to_float(reading)*MAX_WORLD_WIDTH + (MIN_OFFSET);
    if(dot(reading,vec4(1.0)) == 0.0) final_offset.y = 10.0;

    coordinates.x += 1.0/(UNIFORM_BUFFER_WIDTH*6.0);
    reading = texture2D(uniform_buffer, coordinates);
    offset.z = vec4_to_float(reading)*MAX_WORLD_WIDTH + (MIN_OFFSET);
    if(dot(reading,vec4(1.0)) == 0.0) final_offset.z = 10.0;

    //angle
    coordinates.x += 1.0/(UNIFORM_BUFFER_WIDTH*6.0);
    reading = texture2D(uniform_buffer, coordinates);
    angle.x = vec4_to_float(vec4(reading.rg, 0.0, 0.0))*2.0*pi + (MIN_ANGLE);
    if(dot(reading,vec4(1.0)) == 0.0) final_angle.x = 1.0;
    angle.y = vec4_to_float(vec4(reading.ba, 0.0, 0.0))*2.0*pi + (MIN_ANGLE);
    if(dot(reading,vec4(1.0)) == 0.0) final_offset.y = 1.0;

    coordinates.x += 1.0/(UNIFORM_BUFFER_WIDTH*6.0);
    reading = texture2D(uniform_buffer, coordinates);
    angle.z = vec4_to_float(vec4(reading.rg, 0.0, 0.0))*2.0*pi + (MIN_ANGLE);
    if(dot(reading,vec4(1.0)) == 0.0) final_offset.z = 1.0;

    //color and grayscale
    coordinates.x += 1.0/(UNIFORM_BUFFER_WIDTH*6.0);
    reading = texture2D(uniform_buffer, coordinates);
    color.rgb = reading.rgb;
    grayscale = reading.a;
}
