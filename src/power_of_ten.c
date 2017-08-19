/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power_of_ten.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 18:38:18 by calemany          #+#    #+#             */
/*   Updated: 2016/09/30 18:50:06 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static double const		g_power_of_10[] = {
	10.,
	100.,
	1.0e4,
	1.0e8,
	1.0e16,
	1.0e32,
	1.0e64,
	1.0e128,
	1.0e256,
};

static double	power_negative(unsigned int p)
{
	int		i;
	double	value;

	value = 1.;
	i = 0;
	while (p != 0)
	{
		if (p & 1)
			value /= g_power_of_10[i];
		p /= 2;
		++i;
	}
	return (value);
}

static double	power_positive(unsigned int p)
{
	int		i;
	double	value;

	value = 1.;
	i = 0;
	while (p != 0)
	{
		if (p & 1)
			value *= g_power_of_10[i];
		p /= 2;
		++i;
	}
	return (value);
}

int				get_power_of_ten(int p, double *result)
{
	if (p > 308 || p < -324)
		return (1);
	*result = (p >= 0) ? power_positive(p) : power_negative(-p);
	return (0);
}
