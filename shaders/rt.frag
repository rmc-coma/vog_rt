bool			point_is_shadowed(vec3 pos, int light_i)
{
	s_intersection	inter;
	s_ray			ray;
	vec3			obj_to_light;
	float			dist_sq;

	obj_to_light = mix(light[light_i].pos - pos, -light[light_i].dir,
			int(light[light_i].parallel));
	dist_sq = mix(dot(obj_to_light, obj_to_light), INFINITY,
			light[light_i].parallel);
	ray = s_ray(pos, normalize(obj_to_light));
	inter = scene_intersection_find_closer(ray, dist_sq);
	return (inter.exists);
}

vec3			get_phong_color(int mat, vec3 point, vec3 normal, vec3 ray_dir)
{
	int				i;
	s_light			li;
	float			l_intensity;
	vec3			intensity;

	intensity = vec3(0);
	i = 0;
	while (i < n_lights)
	{
		l_intensity = light_get_diffuse_and_specular(i, mat, point, normal,
				ray_dir);
		l_intensity *= float(l_intensity > 0.f
				&& !point_is_shadowed(point, i));
		l_intensity += material[mat].ambiant * light[i].ambiant;
		intensity += light[i].color * l_intensity;
		++i;
	}
	return (material[mat].color * intensity);
}

vec3			get_reflection_color(int mat, vec3 point, vec3 normal,
		vec3 ray_dir)
{
	vec3			color;
	float			reflection;
	s_intersection	inter;
	int				recurse;

	color = vec3(0.f);
	recurse = RECURSE_MAX;
	reflection = material[mat].reflection_indice * float(recurse > 0);
	while (reflection > 0.001)
	{
		ray_dir = reflect(ray_dir, normal);
		inter = process_scene_intersection(s_ray(point, ray_dir));
		if (inter.exists)
		{
			point = inter.point;
			normal = inter.normal;
			mat = mesh[object[inter.object].value_index].material_index;
			color += reflection * get_phong_color(mat, point, normal, ray_dir);
			--recurse;
			reflection *= material[mat].reflection_indice
				* float(recurse > 0);
		}
		else
			reflection = 0.f;
	}
	return (color);
}
