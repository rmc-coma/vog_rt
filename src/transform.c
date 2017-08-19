/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 17:48:07 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/02/28 21:35:09 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"
#include "ft_mem.h"
#include "vector.h"

#include <math.h>
#include <stdio.h>

t_transform	*transform_new(void)
{
	return (transform_init((t_transform *)ft_memalloc(sizeof(t_transform))));
}

t_transform	*transform_init(t_transform *const transform)
{
	if (!transform)
		return ((t_transform *)0);
	vec3_set(&transform->pos, 0.0f, 0.0f, 0.0f);
	vec3_set(&transform->rot, 0.0f, 0.0f, 0.0f);
	vec3_set(&transform->scl, 1.0f, 1.0f, 1.0f);
	return (transform_update_quaternion(transform));
}

t_transform	*transform_update_quaternion(t_transform *const transform)
{
	t_vec3	c;
	t_vec3	s;
	t_vec3	vh;

	vh.x = transform->rot.x / 2.0f;
	vh.y = transform->rot.y / 2.0f;
	vh.z = transform->rot.z / 2.0f;
	c.x = cos(vh.x);
	s.x = sin(vh.x);
	c.y = cos(vh.y);
	s.y = sin(vh.y);
	c.z = cos(vh.z);
	s.z = sin(vh.z);
	transform->qtn.x = s.x * c.y * c.z + c.x * s.y * s.z;
	transform->qtn.y = c.x * s.y * c.z - s.x * c.y * s.z;
	transform->qtn.z = c.x * c.y * s.z + s.x * s.y * c.z;
	transform->qtn.w = c.x * c.y * c.z - s.x * s.y * s.z;
	return (transform);
}

void		transform_apply(t_transform *const t, t_vec3 *v)
{
	double			x;
	double			y;
	double			z;
	double			w;
	t_vec4 const	*q;

	q = &t->qtn;
	vec3_mul(v, &t->scl);
	x = +q->w * v->x + q->y * v->z - q->z * v->y;
	y = +q->w * v->y + q->z * v->x - q->x * v->z;
	z = +q->w * v->z + q->x * v->y - q->y * v->x;
	w = -q->x * v->x - q->y * v->y - q->z * v->z;
	v->x = x * q->w - w * q->x - y * q->z + z * q->y;
	v->y = y * q->w - w * q->y - z * q->x + x * q->z;
	v->z = z * q->w - w * q->z - x * q->y + y * q->x;
	vec3_add(v, &t->pos);
}
