/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_cubic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 22:30:42 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/01 07:57:35 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "constants.h"
#include "cubic.h"
#include "shad_struct.h"
#include "context.h"

t_scene	*scene_init_cubics(t_scene *scene, t_context *context)
{
	ubufferlist_init(&scene->cubics, shad_struct_get(SHAD_CUBIC), context);
	return (scene);
}

t_scene	*scene_add_cubic(t_scene *scene, t_cubic *cubic,
						t_ubuffernode *parent, GLuint parent_slot)
{
	t_ubuffernode	*node;

	node = ubuffernode_new(shad_struct_get(SHAD_CUBIC), cubic);
	ubufferlist_addnode(&scene->cubics, node);
	if (parent)
		ubuffernode_bind(node, parent, parent_slot);
	ubuffernode_setdata(node);
	ubuffernode_subdata(node);
	return (scene);
}

t_scene	*scene_update_cubic(t_scene *scene, t_cubic *cubic)
{
	ubuffernode_subdata(ubufferlist_fetch_node(&scene->cubics, cubic));
	return (scene);
}

t_scene	*scene_bind_cub2geo(t_scene *scene, t_cubic *cubic,
							t_geometry *geometry)
{
	t_ubuffernode	*cubic_node;
	t_ubuffernode	*geometry_node;

	cubic_node = ubufferlist_fetch_node(&scene->cubics, cubic);
	geometry_node = ubufferlist_fetch_node(&scene->geometries, geometry);
	ubuffernode_bind(cubic_node, geometry_node, CONST_GEOMETRY_VALUE_SLOT);
	ubuffernode_setdata(cubic_node);
	ubuffernode_setdata(geometry_node);
	ubuffernode_subdata(cubic_node);
	ubuffernode_subdata(geometry_node);
	return (scene);
}
