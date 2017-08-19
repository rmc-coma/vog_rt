# define REFLECTION 1
# define REFRACTION 2


vec3			get_phong_color_transparency(int mat, vec3 point, vec3 normal,
		vec3 ray_dir)
{
	int				i;
	vec3			l_intensity;
	vec3			intensity;

	intensity = vec3(0);
	i = 0;
	while (i < n_lights)
	{
		l_intensity = scene_point_light_color(point, i);
		l_intensity *= light_get_diffuse_and_specular(i, mat, point,
				normal, ray_dir);
		l_intensity += material[mat].ambiant * light[i].ambiant * light[i].color;
		intensity += l_intensity;
		++i;
	}
	return (material[mat].color * intensity);
}

vec3			surface_color_shadowed(int mat, vec3 point,
		vec3 normal, vec3 ray_dir)
{
#ifdef TRANSPARENCY_SHADOWS
	return (get_phong_color_transparency(mat, point, normal, ray_dir));
#else
	return (get_phong_color(mat, point, normal, ray_dir));
#endif
}

struct			s_step
{
	int				material;
	vec3			point;
	vec3			normal;
	vec3			ray_dir;
	int				todo;
	vec3			intensity;
};

vec3			surface_color_rec(s_intersection inter, vec3 ray_dir)
{
	s_step				stack[RECURSE_MAX+1];
	vec3				color;
	int					i, max;
	int					j, j_max;
	int					mat;
	s_ray				ray;

	mat = mesh[object[inter.object].value_index].material_index;
	color = vec3(0);
	stack[0].material = mat;
	stack[0].point = inter.point;
	stack[0].normal = inter.normal;
	stack[0].ray_dir = ray_dir;
	stack[0].todo = (REFLECTION | REFRACTION) * int(inter.exists);
	stack[0].intensity = vec3(1);
	max = RECURSE_MAX + 1;
	i = 0;
	j = 100;
	while (i >= 0 && j > 0)
	{
		--j;
		if (dot(stack[i].intensity, stack[i].intensity) < OPAQUE_THRESHOLD)
			--i;
		else if (bool(stack[i].todo & REFRACTION))
		{
			mat = stack[i].material;
			stack[i].todo &= ~REFRACTION;
			color += stack[i].intensity
				* (1 - material[mat].refraction)
				* surface_color_shadowed(mat, stack[i].point,
						stack[i].normal, stack[i].ray_dir);
			if (material[mat].refraction > 0. && i < max)
			{
				ray.dir = stack[i].ray_dir;
				ray.pos = stack[i].point
					- 2*INTERSECTION_OFFSET * stack[i].normal;
				++i;
				stack[i].ray_dir = ray.dir;
				inter = process_scene_intersection(ray);
				stack[i].material = mesh[object[inter.object]
					.value_index].material_index;
				stack[i].point = inter.point;
				stack[i].normal = inter.normal;
				stack[i].intensity = stack[i-1].intensity
					* material[mat].refraction
					* material[mat].color;
				stack[i].todo = (REFLECTION | REFRACTION)
					* int(inter.exists);
			}
		}
		else if (bool(stack[i].todo & REFLECTION))
		{
			mat = stack[i].material;
			stack[i].todo &= ~REFLECTION;
			if (material[mat].reflection_indice > 0. && i < max)
			{
				ray.pos = stack[i].point;
				ray.dir = reflect(stack[i].ray_dir,
						stack[i].normal);
				++i;
				stack[i].ray_dir = ray.dir;
				inter = process_scene_intersection(ray);
				stack[i].material = mesh[object[inter.object]
					.value_index].material_index;
				stack[i].point = inter.point;
				stack[i].normal = inter.normal;
				stack[i].intensity = stack[i-1].intensity
					* material[mat].reflection_indice;
				stack[i].todo = (REFLECTION | REFRACTION)
					* int(inter.exists);
			}
		}
		else
			--i;
	}
	return (color);
}
