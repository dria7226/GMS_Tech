if(fragment_mode == FRAGMENT_MRT)
{
  vec4 c = out_Color;

  //calculate target type
  float target_type = mod(gl_FragCoord.x - 0.5, 2.0) + mod(gl_FragCoord.y - 0.5, 2.0)*2.0;

  if(target_type == 0.0)
  {
    // if(stencil)
    // {
    //     if(texture2D(gm_BaseTexture, gl_FragCoord + vec2(0.5)).a == 0.0)
    //     {
    //         discard; return;
    //     }
    // }

    // if(boolean_phase == C_1)
    // {
    //     float relative_depth = dot(vec4(1.0), unpackColor(depth));
    //     if( relative_depth > dot(vec4(1.0), texture2D(boolean_sampler, gl_FragCoord))
    //         &&
    //         relative_depth < dot(vec4(1.0), texture2D(boolean_sampler, gl_FragCoord)))
    //     {
    //         discard; return;
    //     }
    // }

    //DIFFUSE

    //textured
    if(out_TexCoord != vec2(0.0))
    {
      c = texture2D(gm_BaseTexture, out_TexCoord);

      //color
      if(c == vec4(1.0))
        c = vec4(color.rgb, 1.0);

      //grayscale
      if(color.a != 1.0)
      {
        vec4 intensity = (c.rgba + c.gbra + c.brga)/3.0;
        c = mix(intensity, c, color.a);
      }
    }

    gl_FragColor = c; return;

    discard; return;
  }

  if(target_type == 1.0)
  {
      //DEPTH
      gl_FragColor = unpackColor(depth); return;
  }

  if(target_type == 2.0)
  {
      //NORMAL
      gl_FragColor = vec4(normalize(out_Normal)/2.0+vec3(0.5), 1.0); return;
  }

  if(target_type == 3.0)
  {
      //if(boolean_phase == C_1)
      //{
          //mark
      //}

      //EXTRA - LIGHT ACCUMULATION
      vec3 normal = normalize(out_Normal)/2.0 + vec3(0.5);

      //textured
      if(out_TexCoord != vec2(0.0))
      {
        c = texture2D(gm_BaseTexture, out_TexCoord);

        //color
        if(c == vec4(1.0))
          c = vec4(color.rgb, 1.0);

        //grayscale
        if(color.a != 1.0)
        {
          vec4 intensity = (c.rgba + c.gbra + c.brga)/3.0;
          c = mix(intensity, c, color.a);
        }
      }

      vec3 litup = c.rgb*dot(out_Normal,vec3(0.5,-0.25,0.25));
      gl_FragColor = vec4(mix(litup, c.rgb, 0.3), 1.0);
      //gl_FragColor = vec4(vec3(depth), 1.0);
      //gl_FragColor = vec4(normal, 1.0);

      return;
  }

  return;
}
