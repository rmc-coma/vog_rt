/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 08:04:23 by jleu              #+#    #+#             */
/*   Updated: 2017/03/01 08:04:35 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mesh.h"
#include "xml_parsing.h"
#include "material.h"
#include "geometry.h"

#include "libftxml.h"

int			mesh_parse(t_mesh *mesh, t_xml_element const *elem)
{
	t_xml_element const		*child;
	int						err;

	err = 0;
	mesh_init(mesh);
	child = xml_element_find_child(elem, "geometry");
	if (child)
	{
		mesh->geometry = geometry_new();
		err = geometry_parse(mesh->geometry, child);
	}
	if (!err)
	{
		child = xml_element_find_child(elem, "material");
		if (child)
		{
			mesh->material = material_new();
			err = material_parse(mesh->material, child);
		}
	}
	return (err);
}
