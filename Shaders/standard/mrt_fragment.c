if(fragment_mode == FRAGMENT_REGULAR)
{
  vec4 c = out_Color;

  //calculate target type
  float target_type = mod(gl_FragCoord.x - 0.5, 2.0) + mod(gl_FragCoord.y - 0.5, 2.0)*2.0;

  if(target_type == 0.0)
  {
    //DIFFUSE
    if(out_TexCoord != vec2(0.0))
    {
      c = texture2D(gm_BaseTexture, out_TexCoord);

      //color
      if(c == vec4(1.0))
        c = vec4(color, 1.0);

      //grayscale
      if(grayscale != 1.0)
      {
        vec4 intensity = (c.rgba + c.gbra + c.brga)/3.0;
        c = mix(intensity, c, grayscale);
      }
    }

    gl_FragColor = c;
  }

  if(target_type == 1.0)
  {
    //DEPTH
    gl_FragColor = unpackColor(depth);
  }

  if(target_type == 2.0)
  {
    //NORMAL
    gl_FragColor = vec4(normalize(out_Normal)/2.0+vec3(0.5), 1.0);
  }

  if(target_type == 3.0)
  {
      //EXTRA - LIGHT ACCUMULATION
      vec3 normal = normalize(out_Normal)/2.0 + vec3(0.5);
      //vec3 litup = out_Color.rgb*dot(out_Normal,vec3(0.5,-0.25,0.25));
      //gl_FragColor = vec4(mix(litup, out_Color, 0.3), 1.0);
      //gl_FragColor = vec4(vec3(depth), 1.0);
      gl_FragColor = vec4(normal, 1.0);
  }

  return;
}
