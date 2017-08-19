/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 08:04:54 by jleu              #+#    #+#             */
/*   Updated: 2017/03/01 08:06:27 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"
#include "xml_parsing.h"
#include "ft_math.h"
#include "vector.h"

#include "libft.h"
#include "libftxml.h"

#define MATERIAL_FLOAT_COUNT 6

int		material_parse(t_material *mat, t_xml_element const *elem)
{
	static char const	*names[MATERIAL_FLOAT_COUNT] = {
		"ambiant", "diffuse", "specular", "specular_radius", "reflection",
		"refraction"
	};
	float				*values[MATERIAL_FLOAT_COUNT];
	int					err;
	t_xml_element const	*child;

	values[0] = &mat->ambiant;
	values[1] = &mat->diffuse;
	values[2] = &mat->specular;
	values[3] = &mat->specular_radius;
	values[4] = &mat->reflection_indice;
	values[5] = &mat->refraction;
	material_init(mat);
	err = (parse_float_children(elem, MATERIAL_FLOAT_COUNT, names, values) < 0);
	child = xml_element_find_child(elem, "color");
	if (!err && child)
		vec3_parse_color(&mat->color, child);
	mat->reflection_indice = fclamp(mat->reflection_indice, 0, 1);
	mat->refraction = fclamp(mat->refraction, 0, 1);
	return (err);
}
