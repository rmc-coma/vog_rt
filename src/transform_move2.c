/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_move2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 21:37:53 by jleu              #+#    #+#             */
/*   Updated: 2017/02/28 21:38:24 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"
#include "parameters.h"
#include "camera.h"

t_transform	*transform_move_forward(t_transform *transform, Uint32 frametime,
			t_camera *current)
{
	float	c;

	c = MOVE_SPEED * ((float)((float)frametime / 1000.0f));
	transform->pos.x += current->dir.x * c;
	transform->pos.y += current->dir.y * c;
	transform->pos.z += current->dir.z * c;
	transform_update_quaternion(transform);
	return (transform);
}

t_transform	*transform_move_backward(t_transform *transform, Uint32 frametime,
			t_camera *current)
{
	float	c;

	c = MOVE_SPEED * ((float)((float)frametime / 1000.0f));
	transform->pos.x -= current->dir.x * c;
	transform->pos.y -= current->dir.y * c;
	transform->pos.z -= current->dir.z * c;
	return (transform);
}

t_transform	*transform_move_right(t_transform *transform, Uint32 frametime,
			t_camera *current)
{
	float	c;

	c = MOVE_SPEED * ((float)((float)frametime / 1000.0f));
	transform->pos.x += current->right.x * c;
	transform->pos.y += current->right.y * c;
	transform->pos.z += current->right.z * c;
	transform_update_quaternion(transform);
	return (transform);
}
