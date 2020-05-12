if(fragment_mode == FRAGMENT_DEPTH)
{
    float target_type = mod(gl_FragCoord.x - 0.5, 2.0);

    if(boolean_phase == 1)
    {
       if(!(target_type == 0.0 && gl_FrontFacing) &&
         (target_type == 0.0 || gl_FrontFacing))
         discard;
    }

    gl_FragColor = unpackColor(depth); return;
}
