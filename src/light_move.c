/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 03:47:16 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/02/28 04:20:23 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "parameters.h"

t_light	*light_move_left(t_light *light, Uint32 frametime, t_camera *current)
{
	float	c;

	c = MOVE_SPEED * ((float)((float)frametime / 1000.0f));
	light->pos.x -= current->right.x * c;
	light->pos.y -= current->right.y * c;
	light->pos.z -= current->right.z * c;
	return (light);
}

t_light	*light_move_up(t_light *light, Uint32 frametime, t_camera *current)
{
	float	c;

	c = MOVE_SPEED * ((float)((float)frametime / 1000.0f));
	light->pos.x += current->up.x * c;
	light->pos.y += current->up.y * c;
	light->pos.z += current->up.z * c;
	return (light);
}

t_light	*light_move_down(t_light *light, Uint32 frametime, t_camera *current)
{
	float	c;

	c = MOVE_SPEED * ((float)((float)frametime / 1000.0f));
	light->pos.x -= current->up.x * c;
	light->pos.y -= current->up.y * c;
	light->pos.z -= current->up.z * c;
	return (light);
}
