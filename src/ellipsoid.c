/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ellipsoid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 01:14:36 by jleu              #+#    #+#             */
/*   Updated: 2017/03/01 01:16:05 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ellipsoid.h"
#include "quadric.h"
#include "ft_mem.h"
#include "xml_parsing.h"

#include "libftxml.h"

t_ellipsoid	*ellipsoid_new(void)
{
	return (ellipsoid_init((t_ellipsoid *)ft_memalloc(sizeof(t_ellipsoid))));
}

t_ellipsoid	*ellipsoid_init(t_ellipsoid *const ellipsoid)
{
	ellipsoid->radius_x = 1.f;
	ellipsoid->radius_y = 1.f;
	ellipsoid->radius_z = 1.f;
	ellipsoid->quadric.a = 1.f;
	ellipsoid->quadric.b = 1.f;
	ellipsoid->quadric.c = 1.f;
	ellipsoid->quadric.d = 1.f;
	ellipsoid_update_quadric(ellipsoid);
	return (ellipsoid);
}

t_ellipsoid	*ellipsoid_update_quadric(t_ellipsoid *s)
{
	s->quadric.a = s->radius_x * s->radius_x;
	s->quadric.b = s->radius_y * s->radius_y;
	s->quadric.c = s->radius_z * s->radius_z;
	return (s);
}

int			ellipsoid_parse(t_ellipsoid *ellipsoid, t_xml_element const *elem)
{
	int					err;
	static char const	*names[3] = {
				"radius_x", "radius_y", "radius_z"
	};
	float				*values[3];

	values[0] = &ellipsoid->radius_x;
	values[1] = &ellipsoid->radius_y;
	values[2] = &ellipsoid->radius_z;
	ellipsoid_init(ellipsoid);
	err = quadric_parse(&ellipsoid->quadric, elem);
	if (!err)
	{
		err = (parse_float_children(elem, 3, names, values) < 0);
		if (!err)
			ellipsoid_update_quadric(ellipsoid);
	}
	return (err);
}
