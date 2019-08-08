out_Color = in_Color;

#ifdef UNIFORM_COMPRESSION
float color_and_gs = id.a;
color.r = floor(color_and_gs);
color_and_gs = (color_and_gs - color.r)*1000.0;
color.g = floor(color_and_gs);
color_and_gs = (color_and_gs - color.g)*1000.0;
color.b = floor(color_and_gs);
color_and_gs = (color_and_gs - color.b)*1000.0;
color /= byte;
grayscale = color_and_gs/byte;
#else
color = in_color;
grayscale = in_grayscale;
#endif

//no texture
if(in_TexCoord == vec2(0.0))
{
    //perform vertex color setting
    if(out_Color == vec4(1.0))
        out_Color = vec4(color, 1.0);

    //and apply grayscale
    if(grayscale != 1.0)
    {
        vec4 intensity = (out_Color.rgba + out_Color.gbra + out_Color.brga)/3.0;
        out_Color = mix(intensity, out_Color, grayscale);
    }
}

out_TexCoord = in_TexCoord;
