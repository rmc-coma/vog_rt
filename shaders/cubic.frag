struct	s_cubic
{
	int			parent_index;
	vec3		size;
	float		radius;
	float		a3;
	float		a2b;
	float		a2c;
	float		ab2;
	float		abc;
	float		ac2;
	float		b3;
	float		b2c;
	float		bc2;
	float		c3;
	float		a2;
	float		ab;
	float		ac;
	float		b2;
	float		bc;
	float		c2;
	float		a;
	float		b;
	float		c;
	float		d;
};

layout (std140) uniform cubics		{s_cubic			cubic[178];};
uniform int				n_cubics;

vec4	cubic_intersection_coefs(s_cubic c, vec3 pos, vec3 dir)
{
	vec2	x;
	vec2	y;
	vec2	z;
	vec3	coefs_x;
	vec3	coefs_y;
	vec3	coefs_z;
	vec4	coefs;

	x = vec2(dir.x, pos.x);
	y = vec2(dir.y, pos.y);
	z = vec2(dir.z, pos.z);

	coefs_x = polynome_mul22(x, x*c.a3 + y*c.a2b
			+ z*c.a2c
			+ vec2(0, c.a2));
	coefs_x += polynome_mul22(y, y*c.ab2 + z*c.abc
			+ vec2(0, c.ab));
	coefs_x += polynome_mul22(z, z*c.ac2
			+ vec2(0, c.ac));
	coefs_x.z += c.a;

	coefs_y = polynome_mul22(y, y*c.b3 + z*c.b2c
			+ vec2(0, c.b2));
	coefs_y += polynome_mul22(z, z*c.bc2
			+ vec2(0, c.bc));
	coefs_y.z += c.b;

	coefs_z = polynome_mul22(z, z*c.c3 + vec2(0, c.c2));
	coefs_z.z += c.c;

	coefs = polynome_mul32(coefs_x, x);
	coefs += polynome_mul32(coefs_y, y);
	coefs += polynome_mul32(coefs_z, z);
	coefs.w += c.d;
	return (coefs);
}

vec3			cubic_normal(s_cubic c, vec3 p)
{
	vec3	v;
	vec3	normal;

	v.x = 3*c.a3*p.x
		+ 2*(c.a2b*p.y + c.a2c*p.z + c.a2);
	v.y = c.ab2*p.y + c.abc*p.z + c.ab;
	v.z = c.ac2*p.z + c.ac;
	normal.x = dot(v, p) + c.a;

	v.x = c.a2b*p.x + c.ab;
	v.y = 3*c.b3*p.y
		+ 2*(c.b2c*p.z + c.ab2*p.x + c.b2);
	v.z = c.bc2*p.z + c.abc*p.x + c.bc;
	normal.y = dot(v, p) + c.b;

	v.x = c.a2c*p.x + c.abc*p.y + c.ac;
	v.y = c.b2c*p.y + c.bc;
	v.z = 3*c.c3*p.z
		+ 2*(c.ac2*p.x + c.bc2*p.y + c.c2);
	normal.z = dot(v, p) + c.c;

	normal = normalize(normal);
	return (normal);
}

bvec3			cubic_intersection_valid_solution(int index, s_ray ray,
		vec3 sol, int count)
{
	vec3	pos;
	float	radius2;
	bvec3	bsol;

	radius2 = cubic[index].radius * cubic[index].radius;
	pos = ray.pos + sol.z * ray.dir;
	bsol.z = count >= 3 && sol.z > 0.f && dot(pos, pos) < radius2
			&& aabb_includes_point(cubic[index].size, pos);
	pos = ray.pos + sol.y * ray.dir;
	bsol.y = count >= 2 && sol.y > 0.f && dot(pos, pos) < radius2
			&& aabb_includes_point(cubic[index].size, pos);
	pos = ray.pos + sol.x * ray.dir;
	bsol.x = count >= 1 && sol.x > 0.f && dot(pos, pos) < radius2
			&& aabb_includes_point(cubic[index].size, pos);
	return (bsol);
}

float			cubic_intersection_pick_solution(int index, s_ray ray,
		vec3 sol, bvec3 valid)
{
	float	t;

	t = -1.f;
	if (valid.z)
		t = sol.z;
	if (valid.y && (sol.y < t || t < 0.f))
		t = sol.y;
	if (valid.x && (sol.x < t || t < 0.f))
		t = sol.x;
	return (t);
}

s_intersection	process_cubic_intersection(int index, s_ray ray)
{
	s_cubic			cub;
	vec3			pos;
	vec4			coefs;
	s_intersection	inter;
	vec3			sol;
	bvec3			valid;
	int				count;
	float			dist;
	float			t;

	dist = -dot(ray.pos, ray.dir);
	pos = ray.pos + dist * ray.dir;

	cub = cubic[index];

	coefs = cubic_intersection_coefs(cub, pos, ray.dir);

	if (abs(coefs.x) < 0.002)
		sol.xy = polynome2_solve(count, coefs.y, coefs.z, coefs.w);
	else
	{
		coefs.yzw /= coefs.x;
		sol = polynome3_solve(count, coefs.y, coefs.z, coefs.w);
	}
	sol += dist;
	valid = cubic_intersection_valid_solution(index, ray, sol, count);
	t = cubic_intersection_pick_solution(index, ray, sol, valid);
	inter = intersection_from_solution(ray, t);
	inter.count = int(valid.x) + int(valid.y) + int(valid.z);
	inter.normal = cubic_normal(cub, inter.point);
	inter.normal *= -sign(dot(inter.normal, ray.dir));
	return (inter);
}
