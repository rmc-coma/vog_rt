in		vec3			ray_pos;
in		vec3			ray_dir;

layout(location = 0) out		vec4			out_color;

vec3			scene_get_color(s_ray ray)
{
	s_intersection	inter;
	vec3			color;
	int				mat;

	inter = process_scene_intersection(ray);
	if (inter.exists)
	{
#ifdef TRANSPARENCY
		color = surface_color_rec(inter, ray.dir);
#else
		mat = mesh[object[inter.object].value_index].material_index;
		color = surface_color_shadowed(mat, inter.point, inter.normal, ray.dir);
		color += get_reflection_color(mat, inter.point, inter.normal, ray.dir);
#endif
	}
	return (color);
}

void			main(void)
{
	out_color.rgb = scene_get_color(s_ray(ray_pos, ray_dir));
}
