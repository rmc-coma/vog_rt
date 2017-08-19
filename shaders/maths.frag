/*
** Returns the solutions in ascending order. count == 2 or count == 0.
*/
vec2		polynome2_solve(out int count, float a, float b, float c)
{
	float	delta;
	vec2	sol;

	count = 0;
	delta = b * b - 4.0f * a * c;
	if (delta >= 0.0f)
	{
		count = 2;
		sol = (-b + sqrt(delta) * sign(a) * vec2(-1.f, 1.f)) / (a * 2.f);
	}
	return (sol);
}

void	newton3step_vec3(inout vec3 x, float a, float b, float c)
	// one Newton step for x^3 + a*x^2 + b*x + c
{
	vec3 fxs = (3*x+2*a)*x+b;	// f'(x)
	vec3 fx = ((x+a)*x+b)*x+c;	// f(x)
	x -= fx / fxs;
}

vec3		polynome3_solve(out int count, float b, float c, float d)
{
	vec3	sol;
	float	q;
	float	q3;
	float	r, t, D, s, B;

	q = (b * b - 3.f * c) / 9.f;
	q3 = q * q * q;
	r = (b * (9.f * c - 2.f * b * b) - 27.f * d) / 54.f;
	D = r * r - q3;

	if (D < 0.f)
	{
		count = 3;
		if (q == 0.f)
			t = 0.f;
		else
			t = clamp(r / sqrt(q3), -1.f, 1.f);
		t = acos(t);
		s = 2.f * sqrt(q);
		sol = vec3(cos((t + 2.f * M_PI) / 3.f),
				cos(t / 3.f), 
				cos((t - 2.f * M_PI) / 3.f));
		sol = s * sol - b / 3.f;
		// 2 newton steps to fix floating point errors
		newton3step_vec3(sol, b, c, d);
		newton3step_vec3(sol, b, c, d);
	}
	else
	{
		s = pow(abs(r) + sqrt(D), 1.f / 3.f) * sign(r);
		B = (s == 0.f) ? 0.f : q / s;
		sol.x = s + B - b / 3.f; // real root
		sol.y = -0.5f * (s + B) - b / 3.f; // real part of imaginary root
		sol.z = 0.5 * SQRT_3 * (s - B); // imaginary part
		if (abs(sol.z) < eps)
		{
			sol.z = sol.y;
			count = 2;
		}
		else
			count = 1;
	}
	return (sol);
}

vec4	polynome_mul32(vec3 v3, vec2 v2)
{
	vec4	v;

	v.xw = v3.xz * v2;
	v.y = dot(v3.xy, v2.yx);
	v.z = dot(v3.yz, v2.yx);

	return (v);
}

vec3	polynome_mul22(vec2 v0, vec2 v1)
{
	vec3	v;

	v.xz = v0 * v1;
	v.y = dot(v0.xy, v1.yx);

	return (v);
}
