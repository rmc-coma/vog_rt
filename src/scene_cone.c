/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_cone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 03:49:07 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/02/24 06:19:04 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "constants.h"
#include "shad_struct.h"

t_scene	*scene_add_cone(t_scene *scene, t_cone *cone,
			t_ubuffernode *parent, GLuint parent_slot)
{
	t_ubuffernode	*node;

	node = ubuffernode_new(shad_struct_get(SHAD_QUADRIC), cone);
	ubufferlist_addnode(&scene->quadrics, node);
	if (parent)
		ubuffernode_bind(node, parent, parent_slot);
	ubuffernode_setdata(node);
	ubuffernode_subdata(node);
	return (scene);
}

t_scene	*scene_update_cone(t_scene *scene, t_cone *cone)
{
	ubuffernode_subdata(ubufferlist_fetch_node(&scene->quadrics, cone));
	return (scene);
}

t_scene	*scene_bind_con2geo(t_scene *scene, t_cone *cone,
			t_geometry *geometry)
{
	t_ubuffernode	*cone_node;
	t_ubuffernode	*geometry_node;

	cone_node = ubufferlist_fetch_node(&scene->quadrics, cone);
	geometry_node = ubufferlist_fetch_node(&scene->geometries, geometry);
	ubuffernode_bind(cone_node, geometry_node, CONST_GEOMETRY_VALUE_SLOT);
	ubuffernode_setdata(cone_node);
	ubuffernode_setdata(geometry_node);
	ubuffernode_subdata(cone_node);
	ubuffernode_subdata(geometry_node);
	return (scene);
}
