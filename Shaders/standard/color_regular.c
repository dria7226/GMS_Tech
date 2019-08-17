out_Color = in_Color;

#ifdef UNIFORM_COMPRESSION
float compressed_c_and_gs = object_id.a;
color.r = floor(compressed_c_and_gs);
compressed_c_and_gs = (compressed_c_and_gs - color.r)*100.0;
color.g = floor(compressed_c_and_gs);
compressed_c_and_gs = (compressed_c_and_gs - color.g)*100.0;
color.b = floor(compressed_c_and_gs);
color.a = (compressed_c_and_gs - color.b)*100.0;
color /= MAX_COLOR_AND_GS;
#else
color = in_color;
#endif

//no texture
if(in_TexCoord == vec2(0.0))
{
    //perform vertex color setting
    if(out_Color == vec4(1.0))
        out_Color = vec4(color.rgb, 1.0);

    //and apply grayscale
    if(color.a != 1.0)
    {
        vec4 intensity = (out_Color.rgba + out_Color.gbra + out_Color.brga)/3.0;
        out_Color = mix(intensity, out_Color, color.a);
    }
}

out_TexCoord = in_TexCoord;
