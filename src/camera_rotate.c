/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 03:46:11 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/01 04:06:28 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "parameters.h"

t_camera	*camera_rotate_up(t_camera *const camera, const Uint32 frametime,
			t_camera *current)
{
	current->phi += ROTATE_SPEED * ((float)((float)frametime / 1000.0f));
	camera->phi = current->phi;
	camera_update(camera);
	return (camera);
}

t_camera	*camera_rotate_down(t_camera *const camera, const Uint32 frametime,
			t_camera *current)
{
	current->phi -= ROTATE_SPEED * ((float)((float)frametime / 1000.0f));
	camera->phi = current->phi;
	camera_update(camera);
	return (camera);
}

t_camera	*camera_rotate_left(t_camera *const camera, const Uint32 frametime,
			t_camera *current)
{
	current->theta += ROTATE_SPEED * ((float)((float)frametime /
		1000.0f));
	camera->phi = current->phi;
	camera_update(camera);
	return (camera);
}

t_camera	*camera_rotate_right(t_camera *const camera, const Uint32 frametime,
			t_camera *current)
{
	current->theta -= ROTATE_SPEED * ((float)((float)frametime /
		1000.0f));
	camera->phi = current->phi;
	camera_update(camera);
	return (camera);
}
