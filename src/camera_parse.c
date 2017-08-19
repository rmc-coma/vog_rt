/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 03:41:48 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/02/03 04:56:36 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "xml_parsing.h"
#include "vector.h"

#include "libftxml.h"

#define CAMERA_FLOAT_COUNT 4

int			parse_floats(t_camera *camera, t_xml_element const *elem)
{
	static char const	*names[CAMERA_FLOAT_COUNT] = {
		"near", "fov", "phi", "theta"
	};
	float const			*values[CAMERA_FLOAT_COUNT] = {
		&camera->near, &camera->fov, &camera->phi, &camera->theta
	};

	return (parse_float_children(elem, CAMERA_FLOAT_COUNT, names,
		(float **)values) < 0);
}

int			camera_parse(t_camera *camera, t_xml_element const *elem)
{
	int					err;
	t_xml_element const	*child;

	err = parse_floats(camera, elem);
	if (!err)
	{
		child = xml_element_find_child(elem, "position");
		if (child)
			err = vec3_parse(&camera->pos, child);
	}
	return (err);
}
