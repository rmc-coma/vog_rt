struct	s_light
{
	int		parent_index;
	float	intensity;
	float	angle;
	float	ambiant;
	vec3	pos;
	vec3	dir;
	vec3	color;
	bool	parallel;
};

#define LIGHT_PARALLEL_INTENSITY 100

layout (std140) uniform lights			{s_light		light[512];};
uniform	int				n_lights;

float		light_dir_intensity(int index, vec3 light_to_target)
{
	return (light[index].intensity * float(dot(light_to_target,
					light[index].dir) > cos(light[index].angle)));
}

vec3		point_to_light_vec(int light_i, vec3 point)
{
	return (mix(light[light_i].pos - point, -light[light_i].dir,
			int(light[light_i].parallel)));
}

float		point_to_light_dist_sq(int light_i, vec3 point)
{
	vec3	v;

	v = point_to_light_vec(light_i, point);
	return (mix(dot(v, v), INFINITY, light[light_i].parallel));
}
