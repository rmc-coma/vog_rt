/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 03:41:12 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/02/24 06:22:00 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "box.h"
#include "ft_mem.h"
#include "vector.h"
#include "xml_parsing.h"

#include "libftxml.h"

t_box	*box_new(void)
{
	return (box_init((t_box *)ft_memalloc(sizeof(t_box))));
}

t_box	*box_init(t_box *const box)
{
	if (!box)
		return ((t_box *)0);
	vec3_set(&box->size, 1.0f, 1.0f, 1.0f);
	return (box);
}

int		box_parse(t_box *box, t_xml_element const *elem)
{
	t_xml_element const	*child;
	int					err;

	box_init(box);
	err = 0;
	child = xml_element_find_child(elem, "size");
	if (child)
		err = vec3_parse(&box->size, child);
	return (err);
}

void	box_get_aabb(t_box const *box, t_vec3 *min, t_vec3 *max)
{
	*min = box->size;
	*max = box->size;
	vec3_scale(min, -0.5);
	vec3_scale(max, 0.5);
}
