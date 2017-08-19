/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 08:03:10 by jleu              #+#    #+#             */
/*   Updated: 2017/03/01 08:03:12 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "mesh.h"
#include "transform.h"
#include "xml_parsing.h"

#include "libftxml.h"

static int	parse_mesh(t_object *obj, t_xml_element const *elem)
{
	t_xml_element const		*child;
	int						err;

	child = xml_element_find_child(elem, "mesh");
	obj->mesh = mesh_new();
	err = mesh_parse(obj->mesh, child);
	return (err);
}

static int	parse_transform(t_object *obj, t_xml_element const *elem)
{
	t_xml_element const		*child;
	int						err;

	err = 0;
	child = xml_element_find_child(elem, "transform");
	obj->transform = transform_new();
	err = transform_parse(obj->transform, child);
	return (err);
}

int			object_parse(t_object *obj, t_xml_element const *elem)
{
	int						err;

	object_init(obj);
	err = parse_mesh(obj, elem);
	if (!err)
		err = parse_transform(obj, elem);
	if (err)
		object_destruct(obj);
	return (err);
}
