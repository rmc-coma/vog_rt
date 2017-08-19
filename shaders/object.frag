struct s_object
{
	int		parent_index;
	int		value_index;
	int		transform_index;
};


layout (std140) uniform objects			{s_object		object[512];};
uniform int				n_objects;

s_ray			object_transform_inv_ray(int index, s_ray ray)
{
	int				transform_i;

	transform_i = object[index].transform_index;
	ray.pos = transform_apply_inv(transform_i, ray.pos);
	ray.dir = transform_apply_inv_dir(transform_i, ray.dir);
	return (ray);
}

s_intersection	object_transform_intersection(int index, s_intersection inter,
		s_ray ray)
{
	vec3	v;
	int		transform_i;

	transform_i = object[index].transform_index;
	inter.local_point = inter.point;
	inter.point = transform_apply(transform_i, inter.point);
	inter.normal = transform_apply_normal(transform_i, inter.normal);
	v = ray.pos - inter.point;
	inter.point += INTERSECTION_OFFSET * inter.normal;
	inter.dist_sq = dot(v, v);
	inter.object = index;
	//inter.sols *= transform_get_dir_scale(transform_i, ray.dir);
	return (inter);
}

s_intersection	process_object_intersection(int index, s_ray ray)
{
	s_intersection	inter;
	s_ray			local_ray;
	int				geo;

	geo = mesh[object[index].value_index].geometry_index;
	local_ray = object_transform_inv_ray(index, ray);
	if (aabb_intersect_ray(geometry[geo].min, geometry[geo].max, local_ray))
	{
		inter = process_geometry_intersection(geo, local_ray);
		inter = object_transform_intersection(index, inter, ray);
	}
	else
		inter = intersection();
	return (inter);
}

s_intersection	process_scene_intersection(s_ray ray)
{
	int				i;
	s_intersection	inter;
	s_intersection	closest_intersection;

	i = 0;
	closest_intersection = intersection();
	while (i < n_objects)
	{
		inter = process_object_intersection(i, ray);
		if (inter.exists && inter.dist_sq < closest_intersection.dist_sq)
			closest_intersection = inter;
		++i;
	}
	return (closest_intersection);
}

s_intersection	scene_intersection_find_closer(s_ray ray, float dist_sq)
{
	int				i;
	s_intersection	inter;

	i = 0;
	while (i < n_objects)
	{
		inter = process_object_intersection(i, ray);
		if (inter.exists && inter.dist_sq < dist_sq)
			return (inter);
		++i;
	}
	return (intersection());
}

vec3			scene_point_light_color(vec3 p, int light_i)
{
	s_ray			ray;
	float			dist_sq;
	vec3			color;
	s_intersection	inter;
	int				i;
	int				mat;
	bool			opaque;

	opaque = false;
	ray.pos = p;
	ray.dir = normalize(point_to_light_vec(light_i, p));
	dist_sq = point_to_light_dist_sq(light_i, p);
	color = light[light_i].color;
	i = 0;
	while (i < n_objects && !opaque)
	{
		inter = process_object_intersection(i, ray);
		if (inter.exists && inter.dist_sq < dist_sq)
		{
			mat = mesh[object[inter.object].value_index].material_index;
			color *= pow(material[mat].color.rgb * material[mat].refraction,
					vec3(float(inter.count)));
			opaque = (dot(color, color) < OPAQUE_THRESHOLD);
		}
		++i;
	}
	return (color);
}
