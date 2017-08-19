/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_hyperboloid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 07:58:21 by jleu              #+#    #+#             */
/*   Updated: 2017/03/01 07:58:54 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "hyperboloid.h"
#include "constants.h"
#include "shad_struct.h"

t_scene	*scene_add_hyperboloid(t_scene *scene, t_hyperboloid *hyperboloid,
		t_ubuffernode *parent, GLuint parent_slot)
{
	t_ubuffernode	*node;

	node = ubuffernode_new(shad_struct_get(SHAD_QUADRIC), hyperboloid);
	ubufferlist_addnode(&scene->quadrics, node);
	if (parent)
		ubuffernode_bind(node, parent, parent_slot);
	ubuffernode_setdata(node);
	ubuffernode_subdata(node);
	return (scene);
}

t_scene	*scene_update_hyperboloid(t_scene *scene, t_hyperboloid *hyperboloid)
{
	ubuffernode_subdata(ubufferlist_fetch_node(&scene->quadrics, hyperboloid));
	return (scene);
}

t_scene	*scene_bind_hyp2geo(t_scene *scene, t_hyperboloid *hyperboloid,
							t_geometry *geometry)
{
	t_ubuffernode	*hyperboloid_node;
	t_ubuffernode	*geometry_node;

	hyperboloid_node = ubufferlist_fetch_node(&scene->quadrics, hyperboloid);
	geometry_node = ubufferlist_fetch_node(&scene->geometries, geometry);
	ubuffernode_bind(hyperboloid_node, geometry_node,
					CONST_GEOMETRY_VALUE_SLOT);
	ubuffernode_setdata(hyperboloid_node);
	ubuffernode_setdata(geometry_node);
	ubuffernode_subdata(hyperboloid_node);
	ubuffernode_subdata(geometry_node);
	return (scene);
}
