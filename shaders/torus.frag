struct s_torus
{
	int		parent_index;
	float	major_radius;
	float	minor_radius;
};

layout (std140) uniform tori			{s_torus			torus[146];};
uniform int				n_tori;


vec4		torus_intersection_p4_coef(int index, vec3 ray_pos, vec3 ray_dir)
{
	vec4	coef;
	vec3	dd, pp, dp;
	float	dd_sum, dp_sum, pr_sum;
	float	RR;
	vec3	xz = vec3(1., 0., 1.);

	dd = ray_dir * ray_dir;
	dd_sum = dot(ray_dir, ray_dir);
	pp = ray_pos * ray_pos;
	dp = ray_dir * ray_pos;
	dp_sum = dot(ray_dir, ray_pos);
	RR = torus[index].major_radius * torus[index].major_radius;
	pr_sum = dot(ray_pos, ray_pos) + RR
		- torus[index].minor_radius * torus[index].minor_radius;

	coef.yzw = vec3(4.f, 8.f, 4.f) * RR;
	coef.yzw *= -vec3(dot(dd, xz), dot(dp, xz), dot(pp, xz));
	coef.x = 4.f * dd_sum * dp_sum;
	coef.y += 2.f * dd_sum * pr_sum + 4.f * dp_sum * dp_sum;
	coef.z += 4.f * dp_sum * pr_sum;
	coef.w += pr_sum * pr_sum;
	coef /= dd_sum * dd_sum;
	return (coef);
}

int			torus_intersection_solve_polynome4(out vec4 sol,
		int index, s_ray ray)
{
	int		count;
	float	dist;
	vec3	pos;
	vec4	coef;

	// move ray position near the object to avoid floating point errors
	// We use the projection of (0, 0, 0) on the ray,
	// the point closest to (0, 0, 0).
	dist = -dot(ray.pos, ray.dir);
	pos = ray.pos + dist * ray.dir;

	coef = torus_intersection_p4_coef(index, pos, ray.dir);

	count = polynome4_solve(sol, coef.x, coef.y, coef.z, coef.w);
	// correct solutions
	sol += dist;
	return (count);
}

vec3			torus_normal(int index, vec3 surface_pos)
{
	float	RR, pr_sum;
	vec3	normal;

	RR = torus[index].major_radius * torus[index].major_radius;
	pr_sum = dot(surface_pos, surface_pos)
		+ RR - torus[index].minor_radius * torus[index].minor_radius;
	normal = 4.f * (vec3(pr_sum) - vec3(1.f, 0.f, 1.f) * 2.f * RR)
		* surface_pos;
	return (normalize(normal));
}

bool			torus_intersect_aabb(int index, s_ray ray)
{
	vec3	box_min;
	vec3	box_max;
	float	R, r;

	r = torus[index].minor_radius;
	R = torus[index].major_radius + r;
	box_max = vec3(R, r, R);
	box_min = -box_max;
	return (aabb_intersect_ray(box_min, box_max, ray));
}

s_intersection	process_torus_intersection(int index, s_ray ray)
{
	int				count;
	vec4			solutions;
	float			t;
	s_intersection	inter;
	bvec4			bsol;

	inter.exists = torus_intersect_aabb(index, ray);
	if (inter.exists)
	{
		count = torus_intersection_solve_polynome4(solutions, index, ray);

		bsol = bvec4(vec4(greaterThan(vec4(count), vec4(0,1,2,3)))
			* vec4(greaterThan(solutions, vec4(0))));
		solutions = mix(vec4(INFINITY), solutions, bsol);
		solutions.xy = min(solutions.xy, solutions.zw);
		t = min(solutions.x, solutions.y);
		t = mix(t, -1, t == INFINITY);

		inter = intersection_from_solution(ray, t);
		inter.count = int(bsol.x) + int(bsol.y) + int(bsol.z) + int(bsol.w);
		if (inter.exists)
			inter.normal = torus_normal(index, inter.point);
		if (dot(inter.normal, ray.dir) > 0.f)
			inter.normal = -inter.normal;
	}
	return (inter);
}
