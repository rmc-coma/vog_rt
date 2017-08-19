/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 08:02:10 by jleu              #+#    #+#             */
/*   Updated: 2017/03/01 08:02:29 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"
#include "ft_mem.h"
#include "vector.h"

t_material	*material_new(void)
{
	return (material_init((t_material *)ft_memalloc(sizeof(t_material))));
}

t_material	*material_init(t_material *const material)
{
	if (!material)
		return ((t_material *)0);
	material->ambiant = 0.1f;
	material->diffuse = 0.9f;
	material->specular = 0.7f;
	material->specular_radius = 500.0f;
	material->reflection_indice = 0.0f;
	material->refraction = 0.f;
	material->roughness = 0.0f;
	vec3_set(&material->color, 0.1f, 0.1f, 0.1f);
	return (material);
}
