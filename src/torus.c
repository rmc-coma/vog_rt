/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 22:01:35 by jleu              #+#    #+#             */
/*   Updated: 2017/02/28 22:09:58 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "torus.h"
#include "ft_mem.h"
#include "xml_parsing.h"
#include "vector.h"

#include "libftxml.h"

t_torus		*torus_new(void)
{
	return (torus_init((t_torus*)ft_memalloc(sizeof(t_torus))));
}

t_torus		*torus_init(t_torus *torus)
{
	torus->major_radius = 0.9f;
	torus->minor_radius = 0.2f;
	return (torus);
}

int			torus_parse(t_torus *torus, t_xml_element const *elem)
{
	static char const	*names[2] = {
		"major-radius", "minor-radius"
	};
	float				*values[2];

	values[0] = &torus->major_radius;
	values[1] = &torus->minor_radius;
	torus_init(torus);
	return (parse_float_children(elem, 2, names, values) < 0);
}

void		torus_get_aabb(t_torus const *torus, t_vec3 *min, t_vec3 *max)
{
	float	sum;

	sum = torus->major_radius + torus->minor_radius;
	vec3_set(min, -sum, -torus->minor_radius, -sum);
	vec3_set(max, sum, torus->minor_radius, sum);
}
