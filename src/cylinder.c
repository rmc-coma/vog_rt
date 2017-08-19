/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 04:09:00 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/02/24 06:40:02 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"
#include "ft_mem.h"
#include "quadric.h"
#include "xml_parsing.h"
#include "libftxml.h"

t_cylinder	*cylinder_new(void)
{
	return (cylinder_init((t_cylinder *)ft_memalloc(sizeof(t_cylinder))));
}

t_cylinder	*cylinder_init(t_cylinder *const cylinder)
{
	cylinder->radius = 1.0f;
	cylinder->quadric.a = 1.;
	cylinder->quadric.b = 0.;
	cylinder->quadric.c = 1.;
	cylinder_update_quadric(cylinder);
	return (cylinder);
}

t_cylinder	*cylinder_update_quadric(t_cylinder *c)
{
	c->quadric.d = c->radius * c->radius;
	return (c);
}

int			cylinder_parse(t_cylinder *cylinder, t_xml_element const *elem)
{
	static char const	*names[] = {
		"radius"
	};
	float const			*values[] = {
		&cylinder->radius
	};
	int					err;

	cylinder_init(cylinder);
	err = quadric_parse(&cylinder->quadric, elem);
	err = err || parse_float_children(elem, 1, names, (float **)&values[0]) < 0;
	if (!err)
		cylinder_update_quadric(cylinder);
	return (err);
}
