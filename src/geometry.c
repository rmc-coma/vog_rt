/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 03:40:35 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/01 01:30:47 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"
#include "ft_mem.h"
#include "vector.h"
#include <stdlib.h>
#include <float.h>

t_geometry	*geometry_new(void)
{
	return ((t_geometry *)ft_memalloc(sizeof(t_geometry)));
}

t_geometry	*geometry_init(t_geometry *const geometry)
{
	if (!geometry)
		return ((t_geometry *)0);
	geometry->type = GEOMETRY_EMPTY;
	geometry->value.setter = (void *)0;
	return (geometry);
}

t_geometry	*geometry_set(t_geometry *const geometry,
				const t_geometry_type type, void *const value)
{
	if (!geometry)
		return ((t_geometry *)0);
	geometry->type = type;
	geometry->value.setter = value;
	return (geometry);
}

t_geometry	*geometry_destruct(t_geometry *geometry)
{
	free(geometry->value.setter);
	geometry_init(geometry);
	return (geometry);
}

void		geometry_update_aabb(t_geometry *geometry)
{
	if (geometry->type & GEOMETRY_QUADRIC)
		quadric_get_aabb(geometry->value.setter,
				&geometry->min, &geometry->max);
	else if (geometry->type == GEOMETRY_TORUS)
		torus_get_aabb(geometry->value.torus, &geometry->min, &geometry->max);
	else if (geometry->type == GEOMETRY_CUBIC)
		cubic_get_aabb(geometry->value.cubic, &geometry->min, &geometry->max);
	else if (geometry->type == GEOMETRY_BOX)
		box_get_aabb(geometry->value.box, &geometry->min, &geometry->max);
	else if (geometry->type == GEOMETRY_MOBIUS)
		mobius_get_aabb(geometry->value.mobius, &geometry->min, &geometry->max);
	else if (geometry->type == GEOMETRY_PLANE)
		plane_get_aabb(geometry->value.plane, &geometry->min, &geometry->max);
	else
	{
		vec3_set(&geometry->min, -FLT_MAX, -FLT_MAX, -FLT_MAX);
		vec3_set(&geometry->max, FLT_MAX, FLT_MAX, FLT_MAX);
	}
}
