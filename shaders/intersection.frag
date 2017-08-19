struct s_intersection
{
	bool	exists;
	vec3	point;
	vec3	local_point;
	vec3	normal;
	float	dist_sq;
	int		object;
	int		count;
	//vec4	sols;
};

s_intersection	intersection(void)
{
	s_intersection	inter;

	inter.exists = false;
	inter.point = vec3(0.f);
	inter.normal = vec3(0.f);
	inter.dist_sq = INFINITY;
	inter.object = -1;
	inter.count = 0;
	inter.local_point = vec3(0.f);
	//inter.sols = vec4(0);
	return (inter);
}

s_intersection	intersection_from_solution(s_ray ray, float sol)
{
	s_intersection	inter;

	inter.exists = (sol > 0.f);
	inter.point = ray.dir * sol + ray.pos;
	inter.count = int(inter.exists);
	return (inter);
}

s_intersection	intersection_from_polynome2_sol(s_ray ray, vec2 sol, int count)
{
	s_intersection	inter;
	float			t;
	bvec2			valid;

	valid.y = (count >= 2 && sol.y > 0.);
	valid.x = (count >= 1 && sol.x > 0.);
	t = -1;
	if (valid.y)
		t = sol.y;
	if (valid.x && (sol.x < t || t < 0.))
		t = sol.x;

	inter = intersection_from_solution(ray, t);
	inter.count = int(valid.x) + int(valid.y);
	return (inter);
}

s_intersection	intersection_solve_polynome2(float a, float b, float c,
		s_ray ray)
{
	vec2	sol;
	int		count;

	sol = polynome2_solve(count, a, b, c);
	return (intersection_from_polynome2_sol(ray, sol, count));
}
