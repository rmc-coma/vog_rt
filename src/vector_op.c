/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 21:27:35 by jleu              #+#    #+#             */
/*   Updated: 2017/02/28 21:27:37 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "ft_math.h"

t_vec3		*vec3_clamp(t_vec3 *v, float min, float max)
{
	v->x = fclamp(v->x, min, max);
	v->y = fclamp(v->y, min, max);
	v->z = fclamp(v->z, min, max);
	return (v);
}

t_vec3		vec3_max(t_vec3 const *a, t_vec3 const *b)
{
	t_vec3	v;

	v.x = ft_fmax(a->x, b->x);
	v.y = ft_fmax(a->y, b->y);
	v.z = ft_fmax(a->z, b->z);
	return (v);
}

t_vec3		vec3_min(t_vec3 const *a, t_vec3 const *b)
{
	t_vec3	v;

	v.x = ft_fmin(a->x, b->x);
	v.y = ft_fmin(a->y, b->y);
	v.z = ft_fmin(a->z, b->z);
	return (v);
}

void		vec3_add(t_vec3 *a, t_vec3 const *b)
{
	a->x += b->x;
	a->y += b->y;
	a->z += b->z;
}

void		vec3_mul(t_vec3 *a, t_vec3 const *b)
{
	a->x *= b->x;
	a->y *= b->y;
	a->z *= b->z;
}
