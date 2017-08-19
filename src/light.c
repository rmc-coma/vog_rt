/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 03:37:24 by jleu              #+#    #+#             */
/*   Updated: 2017/03/01 03:37:25 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "ft_mem.h"

#include <math.h>
#include <stdlib.h>

t_light	*light_new(void)
{
	return (light_init((t_light *)ft_memalloc(sizeof(t_light))));
}

t_light	*light_init(t_light *const light)
{
	light->angle = (float)M_PI;
	light->intensity = 10.f;
	light->ambiant = 0.5f;
	vec3_set(&light->pos, 0.f, 0.f, 0.f);
	vec3_set(&light->dir, 0.f, 0.f, 1.f);
	vec3_set(&light->color, 1.f, 1.f, 1.f);
	light->parallel = 0;
	return (light);
}

t_light	*light_update(t_light *light)
{
	vec3_normalize(&light->dir);
	vec3_clamp(&light->color, 0.f, 1.f);
	return (light);
}
