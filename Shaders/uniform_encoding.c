if(fragment_mode == FRAGMENT_UNIFORM_ENCODING)
{
    //calculate target type
    float target_type = mod(gl_FragCoord.x - 0.5, 3.0) + mod(gl_FragCoord.y - 0.5, 3.0)*3.0;

    //offset
    if(target_type == 0.0)
    {
        if(pass_offset.x > MAX_OFFSET)
        {
            gl_FragColor = float_to_vec4(1.0); return;
        }

        if(pass_offset.x < MIN_OFFSET)
        {
            gl_FragColor = float_to_vec4(0.0); return;
        }

        gl_FragColor = float_to_vec4((pass_offset.x - (MIN_OFFSET))/MAX_WORLD_WIDTH);
        return;
    }

    if(target_type == 1.0)
    {
        if(pass_offset.y > MAX_OFFSET)
        {
            gl_FragColor = float_to_vec4(1.0); return;
        }

        if(pass_offset.y < MIN_OFFSET)
        {
            gl_FragColor = float_to_vec4(0.0); return;
        }

        gl_FragColor = float_to_vec4((pass_offset.y - (MIN_OFFSET))/MAX_WORLD_WIDTH);
        return;
    }

    if(target_type == 2.0)
    {
        if(pass_offset.z > MAX_OFFSET)
        {
            gl_FragColor = float_to_vec4(1.0); return;
        }

        if(pass_offset.z < MIN_OFFSET)
        {
            gl_FragColor = float_to_vec4(0.0); return;
        }

        gl_FragColor = float_to_vec4((pass_offset.y - (MIN_OFFSET))/MAX_WORLD_WIDTH);
        return;
    }

    //color and grayscale
    if(target_type == 6.0)
    {
        gl_FragColor = vec4(color, grayscale);
        return;
    }

    //angle
    if(target_type == 7.0)
    {
        if(pass_angle.x > MAX_ANGLE)
        {
            gl_FragColor = float_to_vec4(1.0); return;
        }

        if(pass_angle.x < MIN_ANGLE)
        {
            gl_FragColor = float_to_vec4(0.0); return;
        }

        vec4 result = float_to_vec4((pass_angle.x - (MIN_ANGLE))/(2.0*pi));
        gl_FragColor.rg = result.rg;

        if(pass_angle.y > MAX_ANGLE)
        {
            gl_FragColor = float_to_vec4(1.0); return;
        }

        if(pass_angle.y < MIN_ANGLE)
        {
            gl_FragColor = float_to_vec4(0.0); return;
        }

        result = float_to_vec4((pass_angle.y - (MIN_ANGLE))/(2.0*pi));
        gl_FragColor.ba = result.rg;
        return;
    }

    if(target_type == 8.0)
    {
        if(pass_angle.z > MAX_ANGLE)
        {
            gl_FragColor = float_to_vec4(1.0); return;
        }

        if(pass_angle.x < MIN_ANGLE)
        {
            gl_FragColor = float_to_vec4(0.0); return;
        }

        gl_FragColor.rg = float_to_vec4((pass_angle.x - (MIN_ANGLE))/(2.0*pi)).rg;

        gl_FragColor.ba = vec2(0.0);
        return;
    }
}
