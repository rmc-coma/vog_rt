/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 13:21:00 by calemany          #+#    #+#             */
/*   Updated: 2016/09/30 19:42:58 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "power_of_ten.h"

static int				get_str_range(char const *str, char const **begin,
		char const **end)
{
	while (ft_isspace(*str))
		++str;
	*begin = str;
	if (*str == '-' || *str == '+')
		++str;
	while (ft_isdigit(*str))
		++str;
	if (*str == '.')
	{
		++str;
		while (ft_isdigit(*str))
			++str;
	}
	*end = str;
	while (ft_isspace(*str))
		++str;
	return (*str != '\0');
}

static int				digits_to_ull(char const *str, char const *end,
		unsigned long long *result, char const **parsing_end)
{
	unsigned long long	ull;
	unsigned int		max_digits;
	int					point_found;

	ull = 0;
	max_digits = 18;
	point_found = 0;
	while (str != end && max_digits != 0)
	{
		if (ft_isdigit(*str))
		{
			ull *= 10;
			ull += *str - '0';
			--max_digits;
		}
		else
			point_found = 1;
		++str;
	}
	*parsing_end = str;
	*result = ull;
	return (point_found);
}

static char const		*get_point_pos(char const *str, char const *end)
{
	while (str != end && *str != '.')
		++str;
	return (str);
}

static int				get_value(char const *str, char const *end,
		double *result)
{
	unsigned long long	ull;
	char const			*point;
	int					point_found;
	double				value;
	double				power;

	point = get_point_pos(str, end);
	value = 0.;
	point_found = 0;
	while (str != end)
	{
		point_found = digits_to_ull(str, end, &ull, &str) || point_found;
		if (get_power_of_ten(point - str + point_found, &power))
			return (1);
		value += power * (double)ull;
	}
	*result = value;
	return (0);
}

int						double_parse(char const *str, double *result)
{
	int					err;
	char const			*end;
	double				value;
	int					negate;

	err = get_str_range(str, &str, &end);
	value = 0;
	if (!err)
	{
		negate = (*str == '-');
		if (*str == '-' || *str == '+')
			++str;
		while (*str == '0')
			++str;
		err = get_value(str, end, &value);
		*result = (negate) ? -value : value;
	}
	return (err);
}
