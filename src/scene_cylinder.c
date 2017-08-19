/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 04:03:34 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/01 07:57:09 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "constants.h"
#include "shad_struct.h"

t_scene	*scene_add_cylinder(t_scene *scene, t_cylinder *cylinder,
			t_ubuffernode *parent, GLuint parent_slot)
{
	t_ubuffernode	*node;

	node = ubuffernode_new(shad_struct_get(SHAD_QUADRIC), cylinder);
	ubufferlist_addnode(&scene->quadrics, node);
	if (parent)
		ubuffernode_bind(node, parent, parent_slot);
	ubuffernode_setdata(node);
	ubuffernode_subdata(node);
	return (scene);
}

t_scene	*scene_update_cylinder(t_scene *scene, t_cylinder *cylinder)
{
	ubuffernode_subdata(ubufferlist_fetch_node(&scene->quadrics, cylinder));
	return (scene);
}

t_scene	*scene_bind_cyl2geo(t_scene *scene, t_cylinder *cylinder,
			t_geometry *geometry)
{
	t_ubuffernode	*cylinder_node;
	t_ubuffernode	*geometry_node;

	cylinder_node = ubufferlist_fetch_node(&scene->quadrics, cylinder);
	geometry_node = ubufferlist_fetch_node(&scene->geometries, geometry);
	ubuffernode_bind(cylinder_node, geometry_node, CONST_GEOMETRY_VALUE_SLOT);
	ubuffernode_setdata(cylinder_node);
	ubuffernode_setdata(geometry_node);
	ubuffernode_subdata(cylinder_node);
	ubuffernode_subdata(geometry_node);
	return (scene);
}
