struct	s_quadric
{
	int		parent_index;
	float	a;
	float	b;
	float	c;
	float	d;
	vec3	size;
};

layout (std140) uniform quadrics		{s_quadric			quadric[50];};
uniform int				n_quadrics;

vec3				quadric_normal(int i, vec3 p)
{
	return (normalize(vec3(quadric[i].a, quadric[i].b, quadric[i].c) * p));
}

vec3				quadric_intersection_coefs(int index, s_ray ray)
{
	vec3			v, vdir;
	vec3			coefs;

	v = vec3(quadric[index].a, quadric[index].b, quadric[index].c);
	vdir = v * ray.dir;
	coefs.x = dot(ray.dir, vdir);
	coefs.y = 2.f * dot(ray.pos, vdir);
	coefs.z = dot(ray.pos, v * ray.pos) - quadric[index].d;
	return (coefs);
}

s_intersection		process_quadric_intersection(int index, s_ray ray)
{
	vec3			coefs;
	vec2			sol;
	int				count;
	bvec2			bsol;
	s_intersection	inter;

	inter = intersection();
	coefs = quadric_intersection_coefs(index, ray);
	sol = polynome2_solve(count, coefs.x, coefs.y, coefs.z);
	if (count > 0)
	{
		bsol.x = (sol.x > 0 && aabb_includes_point(quadric[index].size,
					ray.pos + sol.x * ray.dir));
		bsol.y = (sol.y > 0 && aabb_includes_point(quadric[index].size,
					ray.pos + sol.y * ray.dir));
		if (bsol.x)
			inter = intersection_from_solution(ray, sol.x);
		else if (bsol.y)
			inter = intersection_from_solution(ray, sol.y);
		inter.count = int(bsol.x) + int(bsol.y);
		inter.normal = quadric_normal(index, inter.point);
		inter.normal *= -sign(dot(ray.dir, inter.normal));
	}
	return (inter);
}
