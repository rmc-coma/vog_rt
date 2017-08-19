/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paraboloid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 07:27:24 by jleu              #+#    #+#             */
/*   Updated: 2017/03/01 07:30:45 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "paraboloid.h"
#include "quadric.h"
#include "ft_mem.h"
#include "xml_parsing.h"

#include "libftxml.h"

t_paraboloid	*paraboloid_new(void)
{
	return (paraboloid_init(ft_memalloc(sizeof(t_paraboloid))));
}

t_paraboloid	*paraboloid_init(t_paraboloid *const paraboloid)
{
	quadric_init(&paraboloid->quadric);
	paraboloid->radius_x = 1.f;
	paraboloid->radius_z = 1.f;
	paraboloid->quadric.a = 1.f;
	paraboloid->quadric.b = -1.f;
	paraboloid->quadric.c = 1.f;
	paraboloid->quadric.d = 0.f;
	paraboloid_update_quadric(paraboloid);
	return (paraboloid);
}

t_paraboloid	*paraboloid_update_quadric(t_paraboloid *s)
{
	if (s->radius_x != 0.f)
		s->quadric.a = ((s->radius_x < 0.f) ? -1.f : 1.f) *
						(1.f / (s->radius_x * s->radius_x));
	else
		s->quadric.a = 1.f;
	if (s->radius_z != 0.f)
		s->quadric.c = ((s->radius_z < 0.f) ? -1.f : 1.f) *
						(1.f / (s->radius_z * s->radius_z));
	else
		s->quadric.c = 1.f;
	return (s);
}

int				paraboloid_parse(t_paraboloid *paraboloid,
				t_xml_element const *elem)
{
	int					err;
	static char const	*names[2] = {
		"radius_x", "radius_z"
	};
	float				*values[2];

	values[0] = &paraboloid->radius_x;
	values[1] = &paraboloid->radius_z;
	paraboloid_init(paraboloid);
	err = quadric_parse(&paraboloid->quadric, elem);
	err = err || (parse_float_children(elem, 2, names, values) < 0);
	if (!err)
		paraboloid_update_quadric(paraboloid);
	return (err);
}
