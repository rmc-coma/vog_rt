/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hyperboloid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 02:52:14 by jleu              #+#    #+#             */
/*   Updated: 2017/03/01 02:53:30 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hyperboloid.h"
#include "quadric.h"
#include "ft_mem.h"
#include "xml_parsing.h"

#include "libftxml.h"

t_hyperboloid	*hyperboloid_new(void)
{
	return (hyperboloid_init(ft_memalloc(sizeof(t_hyperboloid))));
}

t_hyperboloid	*hyperboloid_init(t_hyperboloid *hyperboloid)
{
	hyperboloid->a = 1.f;
	hyperboloid->b = 1.f;
	hyperboloid->c = 1.f;
	hyperboloid->d = 1.f;
	hyperboloid_update_quadric(hyperboloid);
	return (hyperboloid);
}

t_hyperboloid	*hyperboloid_update_quadric(t_hyperboloid *h)
{
	h->quadric.a = (h->a != 0.f) ? 1.f / (h->a * h->a) : 1.f;
	h->quadric.b = -((h->b != 0.f) ? 1.f / (h->b * h->b) : 1.f);
	h->quadric.c = (h->c != 0.f) ? 1.f / (h->c * h->c) : 1.f;
	h->quadric.d = h->d;
	return (h);
}

int				hyperboloid_parse(t_hyperboloid *h, t_xml_element const *elem)
{
	static char const	*names[4] = { "a", "b", "c", "d" };
	float				*values[4];
	int					err;

	values[0] = &h->a;
	values[1] = &h->b;
	values[2] = &h->c;
	values[3] = &h->d;
	hyperboloid_init(h);
	err = quadric_parse(&h->quadric, elem);
	err = err || parse_float_children(elem, 4, names, values) < 0;
	if (!err)
		hyperboloid_update_quadric(h);
	return (err);
}
