/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 03:47:16 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/01 00:42:54 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "parameters.h"

t_camera	*camera_move_left(t_camera *camera, Uint32 frametime,
			t_camera *current)
{
	float	c;

	c = MOVE_SPEED * ((float)((float)frametime / 1000.0f));
	camera->pos.x -= current->right.x * c;
	camera->pos.y -= current->right.y * c;
	camera->pos.z -= current->right.z * c;
	return (camera);
}

t_camera	*camera_move_up(t_camera *camera, Uint32 frametime,
			t_camera *current)
{
	float	c;

	c = MOVE_SPEED * ((float)((float)frametime / 1000.0f));
	camera->pos.x += current->up.x * c;
	camera->pos.y += current->up.y * c;
	camera->pos.z += current->up.z * c;
	return (camera);
}

t_camera	*camera_move_down(t_camera *camera, Uint32 frametime,
			t_camera *current)
{
	float	c;

	c = MOVE_SPEED * ((float)((float)frametime / 1000.0f));
	camera->pos.x -= current->up.x * c;
	camera->pos.y -= current->up.y * c;
	camera->pos.z -= current->up.z * c;
	return (camera);
}
