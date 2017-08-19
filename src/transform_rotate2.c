/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 03:46:11 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/02/28 21:37:11 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"
#include "parameters.h"

t_transform	*transform_rotate_right(t_transform *const transform,
			const Uint32 frametime)
{
	transform->rot.y -= ROTATE_SPEED * ((float)((float)frametime /
		1000.0f));
	transform_update_quaternion(transform);
	return (transform);
}

t_transform	*transform_rotate_forward(t_transform *const transform,
			const Uint32 frametime)
{
	transform->rot.z += ROTATE_SPEED * ((float)((float)frametime /
		1000.0f));
	transform_update_quaternion(transform);
	return (transform);
}

t_transform	*transform_rotate_backward(t_transform *const transform,
			const Uint32 frametime)
{
	transform->rot.z -= ROTATE_SPEED * ((float)((float)frametime /
		1000.0f));
	transform_update_quaternion(transform);
	return (transform);
}
