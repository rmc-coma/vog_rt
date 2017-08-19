/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 03:27:33 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/02/27 22:33:08 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "constants.h"
#include "shad_struct.h"
#include "context.h"

t_scene	*scene_init_planes(t_scene *scene, t_context *context)
{
	ubufferlist_init(&scene->planes, shad_struct_get(SHAD_PLANE), context);
	return (scene);
}

t_scene	*scene_add_plane(t_scene *scene, t_plane *plane,
			t_ubuffernode *parent, GLuint parent_slot)
{
	t_ubuffernode	*node;

	node = ubuffernode_new(shad_struct_get(SHAD_PLANE), plane);
	ubufferlist_addnode(&scene->planes, node);
	if (parent)
		ubuffernode_bind(node, parent, parent_slot);
	ubuffernode_setdata(node);
	ubuffernode_subdata(node);
	return (scene);
}

t_scene	*scene_update_plane(t_scene *scene, t_plane *plane)
{
	ubuffernode_subdata(ubufferlist_fetch_node(&scene->planes, plane));
	return (scene);
}

t_scene	*scene_bind_pln2geo(t_scene *scene, t_plane *plane,
			t_geometry *geometry)
{
	t_ubuffernode	*plane_node;
	t_ubuffernode	*geometry_node;

	plane_node = ubufferlist_fetch_node(&scene->planes, plane);
	geometry_node = ubufferlist_fetch_node(&scene->geometries, geometry);
	ubuffernode_bind(plane_node, geometry_node, CONST_GEOMETRY_VALUE_SLOT);
	ubuffernode_setdata(plane_node);
	ubuffernode_setdata(geometry_node);
	ubuffernode_subdata(plane_node);
	ubuffernode_subdata(geometry_node);
	return (scene);
}
