/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 04:12:31 by jleu              #+#    #+#             */
/*   Updated: 2017/03/01 04:16:39 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "xml_parsing.h"
#include "vector.h"

#include "libftxml.h"

#define LIGHT_FLOAT_COUNT 3

int			light_parse(t_light *light, t_xml_element const *elem)
{
	static char const	*names[LIGHT_FLOAT_COUNT] = {
		"intensity", "angle", "ambiant"};
	float				*values[LIGHT_FLOAT_COUNT];
	t_xml_element const	*child;
	int					err;

	values[0] = &light->intensity;
	values[1] = &light->angle;
	values[2] = &light->ambiant;
	light_init(light);
	err = (parse_float_children(elem, LIGHT_FLOAT_COUNT, names, values) < 0);
	if ((child = xml_element_find_child(elem, "position")))
		err = err || vec3_parse(&light->pos, child);
	if ((child = xml_element_find_child(elem, "direction")))
		err = err || vec3_parse(&light->dir, child);
	if ((child = xml_element_find_child(elem, "color")))
		err = err || vec3_parse_color(&light->color, child);
	if ((child = xml_element_find_child(elem, "parallel")))
		err = err || parse_bool_element(child, &light->parallel);
	if (!err)
		light_update(light);
	return (err);
}
