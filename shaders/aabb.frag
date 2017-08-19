bool			aabb_intersect_ray(vec3 box_min, vec3 box_max, s_ray ray)
{
	vec3	v1;
	vec3	v2;
	vec3	vmin;
	vec3	vmax;
	float	tmin;
	float	tmax;

	v1 = (box_min - ray.pos) / ray.dir;
	v2 = (box_max - ray.pos) / ray.dir;
	vmin = min(v1, v2);
	vmax = max(v1, v2);
	tmin = max(vmin.x, max(vmin.y, vmin.z));
	tmax = min(vmax.x, min(vmax.y, vmax.z));

	return (tmin <= tmax);
}

s_intersection	process_aabb_intersection(vec3 size, s_ray ray)
{
	vec3			v1;
	vec3			v2;
	vec3			vmin;
	vec3			vmax;
	float			tmin;
	float			tmax;
	s_intersection	inter;
	vec3			box_min, box_max;
	vec2			sol;

	vec3			ray_pos;
	float			dist;

	// making sure ray is outside the box
	dist = -dot(ray.pos, ray.dir) - max(max(size.x, size.y), size.z);
	ray_pos = ray.pos + dist * ray.dir;

	box_max = size / 2.f;
	box_min = -box_max;
	v1 = (box_min - ray_pos) / ray.dir;
	v2 = (box_max - ray_pos) / ray.dir;
	vmin = min(v1, v2);
	vmax = max(v1, v2);
	tmin = max(vmin.x, max(vmin.y, vmin.z));
	tmax = min(vmax.x, min(vmax.y, vmax.z));

	if (tmin <= tmax)
	{
		sol = vec2(tmin, tmax) + dist;
		// sol.x <= sol.y
		if (sol.x > 0.) // ray is outside the box
		{
			inter = intersection_from_solution(ray, sol.x);
			inter.normal = vec3(float(tmin == vmin.x),
					float(tmin == vmin.y),
					float(tmin == vmin.z));
			inter.count = 2;
		}
		else // ray is inside the box;
		{
			inter = intersection_from_solution(ray, sol.y);
			inter.normal = vec3(float(tmax == vmax.x),
					float(tmax == vmax.y),
					float(tmax == vmax.z));
			inter.count = 1;
		}
		inter.normal *= -sign(dot(inter.normal, ray.dir));
	}
	else
		inter = intersection();
	return (inter);
}

bool		aabb_includes_point(vec3 size, vec3 point)
{
	return (all(lessThan(abs(point), 0.5 * size)));
}
