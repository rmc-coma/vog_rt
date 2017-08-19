#version 410 core

uniform	sampler2D		frametexture;

uniform	samplerBuffer	text;
uniform int             text_width;
uniform int             text_height;
uniform ivec2           text_pos;

uniform int             s_width;
uniform int             s_height;
uniform	int				c_width;
uniform	int				c_height;

in		vec2			s_coords;

out		vec4			out_color;

void	main()
{
    ivec2   real_coords;
    vec2    frame_coords;
	vec4	texel;

    real_coords.x = int(((s_coords.x + 1.0f) / 2.0f) * float(s_width));
    real_coords.y = int(((s_coords.y * -1.0f + 1.0f) / 2.0f) * float(s_height));
	texel = texelFetch(text, (real_coords.x + real_coords.y * text_width));
    frame_coords = vec2(
        ((s_coords.x * (float(s_width) / float(c_width)) + 1.0f) / 2.0f),
        ((s_coords.y * (float(s_height) / float(c_height)) + 1.0f) / 2.0f));
	out_color = texture(frametexture, frame_coords) * (1.0f - texel.a) * 
        float(frame_coords.x >= 0.0f && frame_coords.x < 1.0f &&
        frame_coords.y >= 0.0f && frame_coords.y < 1.0f) + texel * texel.a;
//	out_color = texel;
}