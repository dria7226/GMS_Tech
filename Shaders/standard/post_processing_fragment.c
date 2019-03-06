if(fragment_mode == FRAGMENT_POST_PROCESSING)
{
  //read from screen
  gl_FragData[0] = texture2D(gm_BaseTexture, out_TexCoord);

  //comic filter
  gl_FragData[0] = vec4(gl_FragData[0].rgb - mod(gl_FragData[0].rgb, 1.0/COMIC_FILTER_RESOLUTION), 1.0);

  //palette snap?

  if(gl_FragData[0].rgb == vec3(0.0))
  {
    //distortion and texturing
  }

  if( gl_FragData[0].rgb != vec3(0.0) &&
      gl_FragData[0].rgb != vec3(1.0))
  {
    //texturing
  }

  //edge compositing
  float edge_reading = texture2D(sampler_a, out_TexCoord).r;

  //temporary implementation:
  if(edge_reading != 0.0)
    gl_FragData[0].rgb *= vec3(1.0 - edge_reading);

    //the more different the color, the less the edge is visible
    //if similar colors are mostly black, make edge white
    //if similar colors are mostly white, make edge black
}
