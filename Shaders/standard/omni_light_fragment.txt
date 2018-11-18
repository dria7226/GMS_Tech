//NOTES
//apply comic hashing in this step
if(fragment_mode == FRAGMENT_OMNI_LIGHT)
{
  //get light position
  //
  gl_FragData[0] = out_Color * texture2D( gm_BaseTexture, out_TexCoord);
  return;
}
