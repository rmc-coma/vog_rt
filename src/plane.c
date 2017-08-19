/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 04:10:16 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/02/24 06:20:12 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"
#include "ft_mem.h"
#include "vector.h"
#include "xml_parsing.h"
#include "libftxml.h"

t_plane	*plane_new(void)
{
	return (plane_init((t_plane *)ft_memalloc(sizeof(t_plane))));
}

t_plane	*plane_init(t_plane *const plane)
{
	vec3_set(&plane->size, 100.f, 0.f, 100.f);
	return (plane);
}

int		plane_parse(t_plane *plane, t_xml_element const *elem)
{
	t_xml_element const	*child;
	int					err;

	plane_init(plane);
	err = 0;
	child = xml_element_find_child(elem, "size");
	if (child)
		err = vec3_parse(&plane->size, child);
	return (err);
}

void	plane_get_aabb(t_plane const *plane, t_vec3 *min, t_vec3 *max)
{
	*min = plane->size;
	*max = plane->size;
	vec3_scale(min, -0.5);
	vec3_scale(max, 0.5);
}
