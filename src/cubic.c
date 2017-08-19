/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 01:12:55 by jleu              #+#    #+#             */
/*   Updated: 2017/03/01 01:13:12 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubic.h"
#include "ft_mem.h"
#include "xml_parsing.h"
#include "vector.h"
#include "ft_math.h"

#include "libftxml.h"

#include <float.h>

#define MAX_SIZE FLT_MAX

t_cubic	*cubic_new(void)
{
	return (cubic_init((t_cubic *)ft_memalloc(sizeof(t_cubic))));
}

t_cubic	*cubic_init(t_cubic *const cubic)
{
	unsigned int	i;

	i = 0;
	while (i < CUBIC_COEF_COUNT)
	{
		cubic->coef[i] = 0.f;
		++i;
	}
	cubic->radius = MAX_SIZE;
	cubic->size = vec3(MAX_SIZE, MAX_SIZE, MAX_SIZE);
	return (cubic);
}

int		cubic_parse(t_cubic *cubic, t_xml_element const *elem)
{
	static char const	*names[CUBIC_COEF_COUNT] = {
		"a3", "a2b", "a2c", "ab2", "abc", "ac2", "b3", "b2c", "bc2", "c3",
		"a2", "ab", "ac", "b2", "bc", "c2", "a", "b", "c", "d"
	};
	int					err;
	t_xml_element const	*child;

	cubic_init(cubic);
	child = xml_element_find_child(elem, "size");
	err = child && vec3_parse(&cubic->size, child);
	if (!err)
		err = parse_float_array(elem, CUBIC_COEF_COUNT, names, cubic->coef) < 0;
	if (!err)
	{
		child = xml_element_find_child(elem, "radius");
		err = child && parse_float_element(child, &cubic->radius);
	}
	return (err);
}

void	cubic_get_aabb(t_cubic const *c, t_vec3 *min, t_vec3 *max)
{
	*max = c->size;
	vec3_scale(max, 0.5);
	max->x = ft_fmin(max->x, c->radius);
	max->y = ft_fmin(max->y, c->radius);
	max->z = ft_fmin(max->z, c->radius);
	*min = *max;
	vec3_scale(min, -1);
}
