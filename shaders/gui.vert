#version 410 core

in		vec2	in_scoords;
out		vec2	s_coords;

void	main()
{
	gl_Position = vec4(in_scoords.x, in_scoords.y, 0.0f, 1.0f);
	s_coords = in_scoords;
}