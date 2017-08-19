/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 03:11:42 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/01 02:28:04 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"
#include "xml_parsing.h"
#include "plane.h"
#include "sphere.h"
#include "ellipsoid.h"
#include "cylinder.h"
#include "cone.h"
#include "torus.h"
#include "box.h"
#include "mobius.h"
#include "hyperboloid.h"
#include "paraboloid.h"

#include "libftxml.h"
#include "libft.h"

static int		parse_type(t_geometry *geo, t_xml_element const *elem)
{
	static t_geometry_type		types[GEOMETRY_TYPE_COUNT] = {
		GEOMETRY_SPHERE, GEOMETRY_PLANE, GEOMETRY_CYLINDER, GEOMETRY_CONE,
		GEOMETRY_TORUS, GEOMETRY_BOX, GEOMETRY_MOBIUS, GEOMETRY_ELLIPSOID
		, GEOMETRY_HYPERBOLOID, GEOMETRY_PARABOLOID, GEOMETRY_CUBIC
	};
	char const					*names[GEOMETRY_TYPE_COUNT] = {
		"sphere", "plane", "cylinder", "cone", "torus", "box", "mobius",
		"ellipsoid", "hyperboloid", "paraboloid", "cubic"
	};
	int							err;
	int							i;

	err = parse_enum_element(elem, GEOMETRY_TYPE_COUNT, names, &i);
	if (!err)
		geo->type = types[i];
	return (err);
}

typedef int(*t_parser)(void*, t_xml_element const *elem);

static void		parse_value3(t_geometry *geo, t_xml_element const *elem,
				int *err)
{
	if (geo->type == GEOMETRY_MOBIUS)
	{
		geo->value.mobius = mobius_new();
		*err = mobius_parse(geo->value.mobius, elem);
	}
	else if (geo->type == GEOMETRY_ELLIPSOID)
	{
		geo->value.ellipsoid = ellipsoid_new();
		*err = ellipsoid_parse(geo->value.ellipsoid, elem);
	}
	else if (geo->type == GEOMETRY_HYPERBOLOID)
	{
		geo->value.hyperboloid = hyperboloid_new();
		*err = hyperboloid_parse(geo->value.hyperboloid, elem);
	}
	else if (geo->type == GEOMETRY_PARABOLOID)
	{
		geo->value.paraboloid = paraboloid_new();
		*err = paraboloid_parse(geo->value.paraboloid, elem);
	}
	else if (geo->type == GEOMETRY_CUBIC)
	{
		geo->value.cubic = cubic_new();
		*err = cubic_parse(geo->value.cubic, elem);
	}
}

static void		parse_value2(t_geometry *geo, t_xml_element const *elem,
				int *err)
{
	if (geo->type == GEOMETRY_CONE)
	{
		geo->value.cone = cone_new();
		*err = cone_parse(geo->value.cone, elem);
	}
	else if (geo->type == GEOMETRY_CYLINDER)
	{
		geo->value.cylinder = cylinder_new();
		*err = cylinder_parse(geo->value.cylinder, elem);
	}
	else if (geo->type == GEOMETRY_TORUS)
	{
		geo->value.torus = torus_new();
		*err = torus_parse(geo->value.torus, elem);
	}
	else if (geo->type == GEOMETRY_BOX)
	{
		geo->value.box = box_new();
		*err = box_parse(geo->value.box, elem);
	}
	else
		parse_value3(geo, elem, err);
}

int				parse_value(t_geometry *geo, t_xml_element const *elem)
{
	int			err;

	err = 0;
	if (geo->type == GEOMETRY_SPHERE)
	{
		geo->value.sphere = sphere_new();
		err = sphere_parse(geo->value.sphere, elem);
	}
	else if (geo->type == GEOMETRY_PLANE)
	{
		geo->value.plane = plane_new();
		err = plane_parse(geo->value.plane, elem);
	}
	else
		parse_value2(geo, elem, &err);
	return (err);
}

int				geometry_parse(t_geometry *geo, t_xml_element const *elem)
{
	t_xml_element const	*child;
	int					err;

	geometry_init(geo);
	err = 0;
	child = xml_element_find_child(elem, "type");
	err = parse_type(geo, child);
	if (!err)
		err = parse_value(geo, elem);
	if (err)
		geometry_destruct(geo);
	else
		geometry_update_aabb(geo);
	return (err);
}
