/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 06:39:52 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/02/28 21:34:46 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <math.h>

t_vec3	vec3(const float x, const float y, const float z)
{
	t_vec3	vec3;

	vec3.x = x;
	vec3.y = y;
	vec3.z = z;
	return (vec3);
}

t_vec3	*vec3_set(t_vec3 *const vec3, const float x,
		const float y, const float z)
{
	vec3->x = x;
	vec3->y = y;
	vec3->z = z;
	return (vec3);
}

t_vec3	*vec3_setp(t_vec3 *const v, const float phi, const float theta)
{
	v->x = cos(phi) * sin(theta);
	v->y = sin(phi);
	v->z = cos(phi) * cos(theta);
	return (vec3_normalize(v));
}

t_vec3	*vec3_normalize(t_vec3 *const v)
{
	float	length;

	length = sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
	v->x /= length;
	v->y /= length;
	v->z /= length;
	return (v);
}

t_vec3	*vec3_scale(t_vec3 *v, const float factor)
{
	v->x *= factor;
	v->y *= factor;
	v->z *= factor;
	return (v);
}
