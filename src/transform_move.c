/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 18:03:04 by jleu              #+#    #+#             */
/*   Updated: 2017/02/28 21:57:19 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"
#include "parameters.h"
#include "camera.h"

t_transform	*transform_move_left(t_transform *t, Uint32 frametime,
								t_camera *current)
{
	float	c;

	c = MOVE_SPEED * ((float)((float)frametime / 1000.0f));
	t->pos.x -= current->right.x * c;
	t->pos.y -= current->right.y * c;
	t->pos.z -= current->right.z * c;
	transform_update_quaternion(t);
	return (t);
}

t_transform	*transform_move_up(t_transform *t, Uint32 frametime,
								t_camera *current)
{
	float	c;

	c = MOVE_SPEED * ((float)((float)frametime / 1000.0f));
	t->pos.x += current->up.x * c;
	t->pos.y += current->up.y * c;
	t->pos.z += current->up.z * c;
	transform_update_quaternion(t);
	return (t);
}

t_transform	*transform_move_down(t_transform *t, Uint32 frametime,
								t_camera *current)
{
	float	c;

	c = MOVE_SPEED * ((float)((float)frametime / 1000.0f));
	t->pos.x -= current->up.x * c;
	t->pos.y -= current->up.y * c;
	t->pos.z -= current->up.z * c;
	transform_update_quaternion(t);
	return (t);
}
