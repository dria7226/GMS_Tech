if(fragment_mode == FRAGMENT_FLAT)
{
  gl_FragColor = out_Color * texture2D( gm_BaseTexture, out_TexCoord);
  return;
}
