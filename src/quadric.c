/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadric.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 07:20:31 by jleu              #+#    #+#             */
/*   Updated: 2017/03/01 07:20:37 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quadric.h"
#include "vector.h"
#include "xml_parsing.h"

#include "libftxml.h"

#include <float.h>

#define MAX_SIZE FLT_MAX

t_quadric	*quadric_init(t_quadric *q)
{
	q->a = 0.f;
	q->b = 0.f;
	q->c = 0.f;
	q->d = 0.f;
	vec3_set(&q->size, MAX_SIZE, MAX_SIZE, MAX_SIZE);
	return (q);
}

int			quadric_parse(t_quadric *q, t_xml_element const *elem)
{
	t_xml_element const *child;
	int					err;

	vec3_set(&q->size, MAX_SIZE, MAX_SIZE, MAX_SIZE);
	err = 0;
	child = xml_element_find_child(elem, "size");
	if (child)
		err = vec3_parse(&q->size, child);
	return (err);
}

void		quadric_get_aabb(t_quadric const *q, t_vec3 *min, t_vec3 *max)
{
	*min = q->size;
	*max = q->size;
	vec3_scale(min, -0.5);
	vec3_scale(max, 0.5);
}
