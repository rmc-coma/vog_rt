/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 18:20:08 by calemany          #+#    #+#             */
/*   Updated: 2017/03/08 17:35:44 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

# include "vector.h"

# include "libftxml.h"

typedef struct	s_material
{
	float		ambiant;
	float		diffuse;
	float		specular;
	float		specular_radius;
	float		reflection_indice;
	float		refraction;
	float		roughness;
	t_vec3		color;
}				t_material;

t_material		*material_new(void);
t_material		*material_init(t_material *const material);
int				material_parse(t_material *mat, t_xml_element const *elem);

#endif
