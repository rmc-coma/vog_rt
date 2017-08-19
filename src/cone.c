/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 00:54:25 by jleu              #+#    #+#             */
/*   Updated: 2017/03/01 00:54:41 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone.h"
#include "ft_mem.h"
#include "quadric.h"
#include "ft_math.h"
#include "xml_parsing.h"

#include "libftxml.h"

#include <math.h>

#define CONE_ANGLE_MAX (M_PI / 2.f - 1e-5)

t_cone	*cone_new(void)
{
	return (cone_init((t_cone *)ft_memalloc(sizeof(t_cone))));
}

t_cone	*cone_init(t_cone *const cone)
{
	cone->quadric.a = 1.f;
	cone->quadric.b = -1.f;
	cone->quadric.c = 1.f;
	cone->quadric.d = 0.f;
	cone->angle = M_PI / 4.f;
	return (cone);
}

t_cone	*cone_update(t_cone *cone)
{
	cone->angle = fclamp(fabs(cone->angle), -CONE_ANGLE_MAX, CONE_ANGLE_MAX);
	cone->quadric.b = -tanf(cone->angle);
	return (cone);
}

int		cone_parse(t_cone *cone, t_xml_element const *elem)
{
	int					err;
	t_xml_element const	*child;

	cone_init(cone);
	err = quadric_parse(&cone->quadric, elem);
	child = xml_element_find_child(elem, "angle");
	if (child && !err)
		err = parse_float_element(child, &cone->angle);
	cone_update(cone);
	return (err);
}
