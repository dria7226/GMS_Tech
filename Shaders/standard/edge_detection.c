if(fragment_mode == FRAGMENT_EDGE_DETECTION)
{
  vec2 offsets[2];
  offsets[0] = vec2(0.0, 1.0);
  offsets[1] = vec2(1.0, 0.0);

  //EDGE
    vec3 delta = abs(
        texture2D(gm_BaseTexture, out_TexCoord + a_pixel.x*offsets[i])
        -
        texture2D(gm_BaseTexture, out_TexCoord - a_pixel.x*offsets[i])).rgb/4.0;

    if(delta.r > THRESHOLD) delta.rgb = vec3(0.25);

    gl_FragColor.rgb += delta;
}
