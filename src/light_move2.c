/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_move2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 04:11:54 by jleu              #+#    #+#             */
/*   Updated: 2017/03/01 04:12:14 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "parameters.h"

t_light	*light_move_forward(t_light *light, Uint32 frametime, t_camera *current)
{
	float	c;

	c = MOVE_SPEED * ((float)((float)frametime / 1000.0f));
	light->pos.x += current->dir.x * c;
	light->pos.y += current->dir.y * c;
	light->pos.z += current->dir.z * c;
	return (light);
}

t_light	*light_move_backward(t_light *light, Uint32 frametime,
							t_camera *current)
{
	float	c;

	c = MOVE_SPEED * ((float)((float)frametime / 1000.0f));
	light->pos.x -= current->dir.x * c;
	light->pos.y -= current->dir.y * c;
	light->pos.z -= current->dir.z * c;
	return (light);
}

t_light	*light_move_right(t_light *light, Uint32 frametime, t_camera *current)
{
	float	c;

	c = MOVE_SPEED * ((float)((float)frametime / 1000.0f));
	light->pos.x += current->right.x * c;
	light->pos.y += current->right.y * c;
	light->pos.z += current->right.z * c;
	return (light);
}
