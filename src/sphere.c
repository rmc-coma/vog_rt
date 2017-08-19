/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 04:09:43 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/02/24 06:20:19 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"
#include "quadric.h"
#include "ft_mem.h"
#include "xml_parsing.h"
#include "libftxml.h"

t_sphere	*sphere_new(void)
{
	return (sphere_init((t_sphere *)ft_memalloc(sizeof(t_sphere))));
}

t_sphere	*sphere_init(t_sphere *const sphere)
{
	sphere->radius = 1.f;
	sphere->quadric.a = 1.f;
	sphere->quadric.b = 1.f;
	sphere->quadric.c = 1.f;
	sphere_update_quadric(sphere);
	return (sphere);
}

t_sphere	*sphere_update_quadric(t_sphere *s)
{
	s->quadric.d = s->radius * s->radius;
	s->quadric.size.x = 2 * s->radius;
	s->quadric.size.y = s->quadric.size.x;
	s->quadric.size.z = s->quadric.size.x;
	return (s);
}

int			sphere_parse(t_sphere *sphere, t_xml_element const *elem)
{
	t_xml_element const	*child;
	int					err;

	sphere_init(sphere);
	err = quadric_parse(&sphere->quadric, elem);
	if (!err)
	{
		child = xml_element_find_child(elem, "radius");
		if (child)
			err = parse_float_element(child, &sphere->radius);
		sphere_update_quadric(sphere);
	}
	return (err);
}
