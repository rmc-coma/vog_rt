/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_ellipsoid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 07:57:49 by jleu              #+#    #+#             */
/*   Updated: 2017/03/01 07:58:09 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "constants.h"
#include "shad_struct.h"

t_scene	*scene_add_ellipsoid(t_scene *scene, t_ellipsoid *ellipsoid,
							t_ubuffernode *parent, GLuint parent_slot)
{
	t_ubuffernode	*node;

	node = ubuffernode_new(shad_struct_get(SHAD_QUADRIC), ellipsoid);
	ubufferlist_addnode(&scene->quadrics, node);
	if (parent)
		ubuffernode_bind(node, parent, parent_slot);
	ubuffernode_setdata(node);
	ubuffernode_subdata(node);
	return (scene);
}

t_scene	*scene_update_ellipsoid(t_scene *scene, t_ellipsoid *ellipsoid)
{
	ubuffernode_subdata(ubufferlist_fetch_node(&scene->quadrics, ellipsoid));
	return (scene);
}

t_scene	*scene_bind_ell2geo(t_scene *scene, t_ellipsoid *ellipsoid,
							t_geometry *geometry)
{
	t_ubuffernode	*ellipsoid_node;
	t_ubuffernode	*geometry_node;

	ellipsoid_node = ubufferlist_fetch_node(&scene->quadrics, ellipsoid);
	geometry_node = ubufferlist_fetch_node(&scene->geometries, geometry);
	ubuffernode_bind(ellipsoid_node, geometry_node, CONST_GEOMETRY_VALUE_SLOT);
	ubuffernode_setdata(ellipsoid_node);
	ubuffernode_setdata(geometry_node);
	ubuffernode_subdata(ellipsoid_node);
	ubuffernode_subdata(geometry_node);
	return (scene);
}
