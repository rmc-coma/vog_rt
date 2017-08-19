#define GEO_QUADRIC		0x00000001
#define GEO_PLANE		0xF1A70000
#define GEO_TORUS		0xBA9E1000
#define GEO_BOX			0xAABB0000
#define GEO_MOBIUS		0xB2000000
#define GEO_CUBIC		0xCBC00000

struct s_plane
{
	int		parent_index;
	vec3	size;
};

struct s_geometry
{
	uint	type;
	int		parent_index;
	int		value_index;
	vec3	min;
	vec3	max;
};

struct	s_box
{
	int		parent_index;
	vec3	size;
};

struct	s_mobius
{
	int		parent_index;
	float	radius;
	float	width;
};

layout (std140) uniform planes			{s_plane			plane[146];};
layout (std140) uniform boxes			{s_box				box[146];};
layout (std140) uniform mobiuses		{s_mobius			mobius[146];};
layout (std140) uniform	geometries		{s_geometry			geometry[512];};

uniform int				n_planes;
uniform int				n_boxes;
uniform int				n_mobiuses;
uniform	int				n_geometries;

s_intersection	process_plane_intersection(int index, s_ray ray)
{
	vec3			normal;
	float			nd;
	float			solution;
	s_intersection	inter;

	normal = vec3(0, 1, 0);
	nd = dot(normal, ray.dir);
	inter.exists = false;
	if (nd != 0.0f)
	{
		solution = -(dot(normal, ray.pos)) / nd;
		inter.point = ray.pos + solution * ray.dir;
		inter.exists = (solution > 0.0f
				&& aabb_includes_point(plane[index].size.xxz, inter.point.xxz));
		inter.normal = -sign(nd) * normal;
		inter.count = 1;
	}
	return (inter);
}

s_intersection	process_box_intersection(int index, s_ray ray)
{
	return (process_aabb_intersection(box[index].size, ray));
}

vec3			mobius_normal(int index, vec3 p)
{
	vec3	normal;
	float	a;
	float	y_z;
	float	x_a;

	a = mobius[index].radius;
	y_z = p.y - p.z;
	x_a = p.x + a;
	normal.x = 2 * (y_z*(p.x + x_a) - x_a*p.y);
	normal.y = y_z*(2*p.y-p.z) + x_a*(p.x-a);
	normal.z = -2 * (p.y*y_z + p.x*x_a);
	return (normal);
}

vec4			mobius_intersection_coefs(int index, vec3 pos, vec3 dir)
{
	vec2			x, y, z;
	vec2			x_a, y_z;
	vec3			v3;
	vec4			coefs;

	x = vec2(dir.x, pos.x);
	y = vec2(dir.y, pos.y);
	z = vec2(dir.z, pos.z);
	y_z	 = y - z;
	x_a = x + vec2(0, mobius[index].radius);
	v3 = polynome_mul22(y_z, y_z);
	v3 -= polynome_mul22(x_a, x_a);
	coefs = polynome_mul32(v3, y);
	v3 = polynome_mul22(y_z, x_a);
	coefs += 2*polynome_mul32(v3, x);
	return (coefs);
}

bool			mobius_inside(int index, vec3 pos)
{
	float x, y, z;
	float t, s;
	float radius = mobius[index].radius;
	float half_width = 0.5 * mobius[index].width;
	float epsilon = 1e-7;
	float cost, sint, cost2, sint2;

	x = pos.x, y = pos.y, z = pos.z;

	t = atan(y, x);
	cost = cos(t);
	sint = sin(t);
	cost2 = cos(t/2);
	sint2 = sin(t/2);
	if (abs(sint2) > epsilon)
	{
		s = z / sint2;
	}	
	else
	{
		if (abs(cost) > epsilon)
			s = (x / cost - radius) / cost2;
		else
			s = (y / sint - radius) / cost2;
	}
	x -= (radius + s * cost2) * cost;
	y -= (radius + s * cost2) * sint;
	z -= s * sint2;
	if (pos.x < 0. && abs(x * x + y * y + z * z) > epsilon)
		return false;
	return (abs(s) <= half_width + epsilon);
}

s_intersection	process_mobius_intersection(int index, s_ray ray)
{
	vec4			coefs;
	vec3			sol;
	int				count;
	float			t;
	s_intersection	inter;
	vec3			pos;
	float			dist;
	bvec3			bsol;

	dist = -dot(ray.pos, ray.dir);
	pos = ray.pos + dist * ray.dir;

	coefs = mobius_intersection_coefs(index, pos, ray.dir);
	coefs.yzw /= coefs.x;

	sol = polynome3_solve(count, coefs.y, coefs.z, coefs.w);
	sol += dist;
	t = -1.f;
	bsol.z = (count >= 3 && sol.z > 0.f
			&& mobius_inside(index, ray.pos + sol.z*ray.dir));
	bsol.y = (count >= 2 && sol.y > 0.f
			&& mobius_inside(index, ray.pos + sol.y*ray.dir));
	bsol.x = (count >= 1 && sol.x > 0.f
			&& mobius_inside(index, ray.pos + sol.x*ray.dir));
	if (bsol.z)
		t = sol.z;
	if (bsol.y && (sol.y < t || t < 0.f))
		t = sol.y;
	if (bsol.x && (sol.x < t || t < 0.f))
		t = sol.x;
	inter = intersection_from_solution(ray, t);
	inter.count = int(bsol.x) + int(bsol.y) + int(bsol.z);
	inter.normal = mobius_normal(index, inter.point);
	inter.normal *= -sign(dot(inter.normal, ray.dir));
	return (inter);
}

s_intersection	process_geometry_intersection(int index, s_ray ray)
{
	s_intersection		inter;

	if (bool(geometry[index].type & uint(GEO_QUADRIC)))
		inter = process_quadric_intersection(geometry[index].value_index, ray);
	else if (geometry[index].type == GEO_PLANE)
		inter = process_plane_intersection(geometry[index].value_index, ray);
	else if (geometry[index].type == GEO_TORUS)
		inter = process_torus_intersection(geometry[index].value_index, ray);
	else if (geometry[index].type == GEO_BOX)
		inter = process_box_intersection(geometry[index].value_index, ray);
	else if (geometry[index].type == GEO_MOBIUS)
		inter = process_mobius_intersection(geometry[index].value_index, ray);
	else if (geometry[index].type == GEO_CUBIC)
		inter = process_cubic_intersection(geometry[index].value_index, ray);
	else
		inter = intersection();
	return (inter);
}
