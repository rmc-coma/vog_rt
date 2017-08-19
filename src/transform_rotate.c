/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 03:46:11 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/01 04:06:13 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"
#include "parameters.h"

t_transform	*transform_rotate_up(t_transform *const transform,
			const Uint32 frametime)
{
	transform->rot.x += ROTATE_SPEED
						* ((float)((float)frametime / 1000.0f));
	transform_update_quaternion(transform);
	return (transform);
}

t_transform	*transform_rotate_down(t_transform *const transform,
			const Uint32 frametime)
{
	transform->rot.x -= ROTATE_SPEED
						* ((float)((float)frametime / 1000.0f));
	transform_update_quaternion(transform);
	return (transform);
}

t_transform	*transform_rotate_left(t_transform *const transform,
			const Uint32 frametime)
{
	transform->rot.y += ROTATE_SPEED * ((float)((float)frametime /
		1000.0f));
	transform_update_quaternion(transform);
	return (transform);
}
