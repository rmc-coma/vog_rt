/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 17:09:37 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/02/06 20:48:18 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "error.h"
#include "parameters.h"
#include "vector.h"
#include "camera.h"
#include "ft_mem.h"

t_camera	*camera_new(void)
{
	return (camera_init((t_camera *)ft_memalloc(sizeof(t_camera))));
}

t_camera	*camera_init(t_camera *const camera)
{
	camera->near = CAMERA_DEFAULT_NEAR;
	camera->fov = CAMERA_DEFAULT_FOV;
	camera->phi = 0.0f;
	camera->theta = 0.0f;
	vec3_set(&camera->pos, 0.0f, 0.0f, 0.0f);
	camera_update(camera);
	return (camera);
}

t_camera	*camera_update(t_camera *camera)
{
	if (camera->phi > 90.f)
		camera->phi = 90.f;
	else if (camera->phi < -90.f)
		camera->phi = -90.f;
	if (camera->theta > 180.0f)
		camera->theta -= 360.0f;
	else if (camera->theta < -180.0f)
		camera->theta += 360.0f;
	vec3_setp(&camera->dir, RAD(camera->phi), RAD(camera->theta));
	vec3_setp(&camera->up, RAD(camera->phi + 90.0f), RAD(camera->theta));
	vec3_setp(&camera->right, 0.0f, RAD(camera->theta - 90.0f));
	return (camera);
}
