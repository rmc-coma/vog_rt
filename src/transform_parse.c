/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 21:38:38 by jleu              #+#    #+#             */
/*   Updated: 2017/02/28 21:38:40 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"
#include "xml_parsing.h"

#include "libftxml.h"

int		transform_parse(t_transform *transform, t_xml_element const *elem)
{
	int					err;
	t_xml_element const	*child;

	transform_init(transform);
	err = 0;
	child = xml_element_find_child(elem, "position");
	if (child)
		err = vec3_parse(&transform->pos, child);
	if (!err)
	{
		child = xml_element_find_child(elem, "rotation");
		if (child)
			err = vec3_parse(&transform->rot, child);
	}
	if (!err)
	{
		child = xml_element_find_child(elem, "scale");
		if (child)
			err = vec3_parse(&transform->scl, child);
	}
	if (!err)
		transform_update_quaternion(transform);
	return (err);
}
