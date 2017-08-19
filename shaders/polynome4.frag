void	complex_sqrt(float x, float y, out float a, out float b)
// returns:  a+i*b = sqrt(x+i*y)
{
	float	r;

	r = sqrt(x * x + y * y);

	if (y == 0.)
	{ 
		r = sqrt(r);
		a = float(x >= 0.) * r;
		b = float(x < 0.) * r;
	}
	else
	{
		a = sqrt(0.5 * (x + r));
		b = 0.5 * y / a;
	}
}

int		solve_p4_bi(out vec4 sol, float b, float d)
	// solve equation x^4 + b*x^2 + d = 0
{
	float	D, sD;
	vec2	x;
	int		count;
	
	count = 0;
	D = b * b - 4. * d;
	if (D >= 0.) 
	{
		sD = sqrt(D);
		x = (-b + sD * vec2(1., -1.)) / 2.; // x.y <= x.x
		x = sqrt(abs(x));
		sol = vec4(-x.x, x.x, -x.y, x.y);
		// if 0 <= x.y <= x.x, 4 real roots
		// if x.y <= x.x < 0, two pair of imaginary roots
		// if x.y < 0 <= x.x , two real roots and one pair of imginary root
		count = 2 * (int(x.x >= 0.) + int(x.y >= 0.));
	} // if( D < 0 ), two pair of compex roots
	return (count);
}

int		solve_p4_de(out vec4 sol, float b, float c, float d)
	// solve equation x^4 + b*x^2 + c*x + d
{
	float	s, szr, szi;
	vec3	sz;
	int		res3, count;

	//if(abs(c) < 1e-14 *(abs(b) + abs(d)))
	//	return (solve_p4_bi(sol, b, d)); // After that, c!=0

	count = 0;
	sol.xyz = polynome3_solve(res3, 2.*b, b*b-4.*d, -c*c);	// solve resolvent
	// by Viet theorem:  x1*x2*x3=-c*c not equals to 0, so x1!=0, x2!=0, x3!=0
	if(res3 > 1)	// 3 real roots, 
	{				
		// Note: sol.x*sol.y*sol.z = c*c > 0
		if (min(min(sol.x, sol.y), sol.z) > 0.) // all roots are positive
		{
			count = 4;
			sz = sqrt(sol.xyz);
			// Note: sz1*sz2*sz3= -c (and not equal to 0)
			sol = mat3x4(-1,-1,1,1,-1,1,-1,1,
					vec4(-1, 1, 1, -1) * sign(c)) * sz / 2.;
			/*if(c > 0.)
			{
				//sol.x = (-sz1 -sz2 -sz3)/2;
				//sol.y = (-sz1 +sz2 +sz3)/2;
				//sol.z = (+sz1 -sz2 +sz3)/2;
				//sol.w = (+sz1 +sz2 -sz3)/2;
				sol = mat3x4(-1,-1,1,1,-1,1,-1,1,-1,1,1,-1) * sz / 2;;
			}
			else
			{
				// now: c<0
				//sol.x = (-sz1 -sz2 +sz3)/2;
				//sol.y = (-sz1 +sz2 -sz3)/2;
				//sol.z = (+sz1 -sz2 -sz3)/2;
				//sol.w = (+sz1 +sz2 +sz3)/2;
				sol = mat3x4(-1,-1,1,1,-1,1,-1,1,1,-1,-1,1) * sz / 2;;
			}*/
		}
	}
	else
	{
		// now resoventa have 1 real and pair of compex roots
		// sol.x - real root, and sol.x>0,
		// sol.y±i*sol.z - complex roots,
		// sol.x must be >=0. But one times sol.x=~ 1e-17, so:
		s = sqrt(max(sol.x, 0.));
		complex_sqrt(sol.y, sol.z, szr, szi);  // (szr+i*szi)^2 = sol.y+i*sol.z
		sol.xy = szr * vec2(-1, 1) - sign(c) * s / 2.;
		count = 2;
	}
	return (count);
}

void	newton4step_vec4(inout vec4 x, float a, float b, float c, float d)
	// one Newton step for x^4 + a*x^3 + b*x^2 + c*x + d
{
	vec4 fxs = ((4*x+3*a)*x+2*b)*x+c;	// f'(x)
	vec4 fx = (((x+a)*x+b)*x+c)*x+d;	// f(x)
	x -= fx / fxs;
}

// x - array of size 4
// return 4: 4 real roots sol.x, sol.y, sol.z, sol.w, possible multiple roots
// return 2: 2 real roots sol.x, sol.y and complex sol.z±i*sol.w, 
// return 0: two pair of complex roots: sol.x±i*sol.y,  sol.z±i*sol.w, 
int		polynome4_solve(out vec4 sol, float a, float b, float c, float d) {
	// solve equation x^4 + a*x^3 + b*x^2 + c*x + d by Dekart-Euler method
	// move to a=0:
	float	aa = a * a;
	float	d1 = d + 0.25*a*(0.25*b*a - 3./64.*aa*a - c);
	float	c1 = c + 0.5*a*(0.25*aa - b);
	float	b1 = b - 0.375*aa;

	int res = solve_p4_de(sol, b1, c1, d1);

	sol -= a / 4.;

	// one Newton step for each real root:
	newton4step_vec4(sol, a, b, c, d);
	return (res);
}
