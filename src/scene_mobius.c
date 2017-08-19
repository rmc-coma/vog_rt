/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_mobius.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 03:32:57 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/02/27 22:33:00 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "constants.h"
#include "mobius.h"
#include "shad_struct.h"
#include "context.h"

t_scene	*scene_init_mobius(t_scene *scene, t_context *context)
{
	ubufferlist_init(&scene->mobius, shad_struct_get(SHAD_MOBIUS), context);
	return (scene);
}

t_scene	*scene_add_mobius(t_scene *scene, t_mobius *mobius,
			t_ubuffernode *parent, GLuint parent_slot)
{
	t_ubuffernode	*node;

	node = ubuffernode_new(shad_struct_get(SHAD_MOBIUS), mobius);
	ubufferlist_addnode(&scene->mobius, node);
	if (parent)
		ubuffernode_bind(node, parent, parent_slot);
	ubuffernode_setdata(node);
	ubuffernode_subdata(node);
	return (scene);
}

t_scene	*scene_update_mobius(t_scene *scene, t_mobius *mobius)
{
	ubuffernode_subdata(ubufferlist_fetch_node(&scene->mobius, mobius));
	return (scene);
}

t_scene	*scene_bind_mob2geo(t_scene *scene, t_mobius *mobius,
			t_geometry *geometry)
{
	t_ubuffernode	*mobius_node;
	t_ubuffernode	*geometry_node;

	mobius_node = ubufferlist_fetch_node(&scene->mobius, mobius);
	geometry_node = ubufferlist_fetch_node(&scene->geometries, geometry);
	ubuffernode_bind(mobius_node, geometry_node, CONST_GEOMETRY_VALUE_SLOT);
	ubuffernode_setdata(mobius_node);
	ubuffernode_setdata(geometry_node);
	ubuffernode_subdata(mobius_node);
	ubuffernode_subdata(geometry_node);
	return (scene);
}
