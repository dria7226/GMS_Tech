out_Color = in_Color;

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
