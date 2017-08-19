/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 23:17:38 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/01 08:04:13 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "ft_mem.h"
#include "mesh.h"
#include "transform.h"
#include "geometry.h"

#include <stdlib.h>

t_object	*object_new(void)
{
	return ((t_object *)ft_memalloc(sizeof(t_object)));
}

t_object	*object_init(t_object *const object)
{
	object->mesh = (void *)0;
	object->transform = (void *)0;
	return (object);
}

t_object	*object_set(t_object *const object, t_mesh *const mesh,
			t_transform *const transform)
{
	object->mesh = mesh;
	object->transform = transform;
	return (object);
}

t_object	*object_destruct(t_object *object)
{
	free(object->transform);
	if (object->mesh)
		mesh_destruct(object->mesh);
	object_init(object);
	return (object);
}
