#version 410 core

struct s_camera
{
	int		parent_index;
	float	near;
	float	fov;
	vec3	pos;
	float	phi;
	vec3	dir;
	float	theta;
	vec3	up;
	float	rho;
	vec3	right;
};

layout (std140) uniform		cameras         {s_camera       camera[64];};

				uniform		int				n_cameras;
				uniform		int				current_camera;

uniform	float	s_ratio;

in		vec2	in_scoords;

out		vec3	ray_pos;
out		vec3	ray_dir;

vec2	get_camera_plane_view_size(float near, float fov, float aspect)
{
	float	top;
	vec2	size;

	top = near * tan(radians(0.5f * fov));
	size.y = top;
	size.x = aspect * size.y;
	return (size);
}

void	main()
{
	vec2	view_plane_size;
	vec3	cam_to_view_plane;
	vec3	right;
	vec3	up;
	vec2	scoords;

	view_plane_size = get_camera_plane_view_size(camera[current_camera].near,
												camera[current_camera].fov,
												s_ratio);
	cam_to_view_plane = camera[current_camera].near * normalize(camera[current_camera].dir);
	right = camera[current_camera].right;
	up = camera[current_camera].up;

	gl_Position = vec4(in_scoords.x, in_scoords.y, 0.0f, 1.0f);

	scoords = in_scoords * view_plane_size;
	ray_pos = camera[current_camera].pos + cam_to_view_plane;
	ray_dir = normalize(cam_to_view_plane + scoords.x * right + scoords.y * up);
}
