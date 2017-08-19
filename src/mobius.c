/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mobius.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 04:10:36 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/01 08:06:52 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mobius.h"
#include "ft_mem.h"
#include "xml_parsing.h"
#include "vector.h"
#include "libftxml.h"

t_mobius		*mobius_new(void)
{
	return (mobius_init((t_mobius*)ft_memalloc(sizeof(t_mobius))));
}

t_mobius		*mobius_init(t_mobius *m)
{
	m->radius = 1.f;
	m->width = 0.5f;
	return (m);
}

int				mobius_parse(t_mobius *mobius, t_xml_element const *elem)
{
	static char const	*names[] = {
		"radius", "width"
	};
	float const			*values[] = {
		&mobius->radius, &mobius->width
	};

	mobius_init(mobius);
	return (parse_float_children(elem, 2, names, (float **)values) < 0);
}

void			mobius_get_aabb(t_mobius const *mobius,
		t_vec3 *min, t_vec3 *max)
{
	float	m;

	m = mobius->radius + mobius->width;
	vec3_set(max, m + mobius->width, m, mobius->width * 2.);
	vec3_set(min, mobius->radius * -1.1, m * -1.1, mobius->width * -2.);
}
