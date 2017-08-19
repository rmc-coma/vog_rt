/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 21:32:04 by jleu              #+#    #+#             */
/*   Updated: 2017/02/28 21:45:23 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "xml_parsing.h"
#include "libftxml.h"

int		vec3_parse(t_vec3 *vec, t_xml_element const *elem)
{
	static char const	*names[3] = {
		"x", "y", "z"
	};
	float				*values[3];

	values[0] = &vec->x;
	values[1] = &vec->y;
	values[2] = &vec->z;
	return (parse_float_children(elem, 3, names, values) < 0);
}

int		vec3_parse_color(t_vec3 *vec, t_xml_element const *elem)
{
	static char const	*names[3] = {
		"r", "g", "b"
	};
	float				*values[3];

	values[0] = &vec->x;
	values[1] = &vec->y;
	values[2] = &vec->z;
	return (parse_float_children(elem, 3, names, values) < 0);
}
