/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_paraboloid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 07:34:00 by jleu              #+#    #+#             */
/*   Updated: 2017/03/01 07:34:28 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "constants.h"
#include "shad_struct.h"
#include "paraboloid.h"

t_scene	*scene_add_paraboloid(t_scene *scene, t_paraboloid *paraboloid,
							t_ubuffernode *parent, GLuint parent_slot)
{
	t_ubuffernode	*node;

	node = ubuffernode_new(shad_struct_get(SHAD_QUADRIC), paraboloid);
	ubufferlist_addnode(&scene->quadrics, node);
	if (parent)
		ubuffernode_bind(node, parent, parent_slot);
	ubuffernode_setdata(node);
	ubuffernode_subdata(node);
	return (scene);
}

t_scene	*scene_update_paraboloid(t_scene *scene, t_paraboloid *paraboloid)
{
	ubuffernode_subdata(ubufferlist_fetch_node(&scene->quadrics, paraboloid));
	return (scene);
}

t_scene	*scene_bind_par2geo(t_scene *scene, t_paraboloid *paraboloid,
							t_geometry *geometry)
{
	t_ubuffernode	*paraboloid_node;
	t_ubuffernode	*geometry_node;

	paraboloid_node = ubufferlist_fetch_node(&scene->quadrics, paraboloid);
	geometry_node = ubufferlist_fetch_node(&scene->geometries, geometry);
	ubuffernode_bind(paraboloid_node, geometry_node, CONST_GEOMETRY_VALUE_SLOT);
	ubuffernode_setdata(paraboloid_node);
	ubuffernode_setdata(geometry_node);
	ubuffernode_subdata(paraboloid_node);
	ubuffernode_subdata(geometry_node);
	return (scene);
}
