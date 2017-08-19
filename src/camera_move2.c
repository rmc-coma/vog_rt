/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_move2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 03:46:56 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/01 00:43:47 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "parameters.h"

t_camera	*camera_move_forward(t_camera *camera, Uint32 frametime,
			t_camera *current)
{
	float	c;

	c = MOVE_SPEED * ((float)((float)frametime / 1000.0f));
	camera->pos.x += current->dir.x * c;
	camera->pos.y += current->dir.y * c;
	camera->pos.z += current->dir.z * c;
	return (camera);
}

t_camera	*camera_move_backward(t_camera *camera, Uint32 frametime,
			t_camera *current)
{
	float	c;

	c = MOVE_SPEED * ((float)((float)frametime / 1000.0f));
	camera->pos.x -= current->dir.x * c;
	camera->pos.y -= current->dir.y * c;
	camera->pos.z -= current->dir.z * c;
	return (camera);
}

t_camera	*camera_move_right(t_camera *camera, Uint32 frametime,
			t_camera *current)
{
	float	c;

	c = MOVE_SPEED * ((float)((float)frametime / 1000.0f));
	camera->pos.x += current->right.x * c;
	camera->pos.y += current->right.y * c;
	camera->pos.z += current->right.z * c;
	return (camera);
}
