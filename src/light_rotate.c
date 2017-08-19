/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 04:40:28 by jleu              #+#    #+#             */
/*   Updated: 2017/03/01 04:40:32 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "parameters.h"
#include "vector.h"

t_light	*light_rotate_up(t_light *light, Uint32 frametime, t_camera *current)
{
	current->phi += ROTATE_SPEED * ((float)((float)frametime / 1000.0f));
	vec3_setp(&light->dir, current->phi, current->theta);
	light_update(light);
	return (light);
}

t_light	*light_rotate_down(t_light *light, Uint32 frametime, t_camera *current)
{
	current->phi -= ROTATE_SPEED * ((float)((float)frametime / 1000.0f));
	vec3_setp(&light->dir, current->phi, current->theta);
	light_update(light);
	return (light);
}

t_light	*light_rotate_left(t_light *light, Uint32 frametime, t_camera *current)
{
	current->theta += ROTATE_SPEED * ((float)((float)frametime / 1000.0f));
	vec3_setp(&light->dir, current->phi, current->theta);
	light_update(light);
	return (light);
}

t_light	*light_rotate_right(t_light *light, Uint32 frametime, t_camera *current)
{
	current->theta -= ROTATE_SPEED * ((float)((float)frametime / 1000.0f));
	vec3_setp(&light->dir, current->phi, current->theta);
	light_update(light);
	return (light);
}
