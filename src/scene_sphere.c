/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 03:55:29 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/01 07:33:48 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "constants.h"
#include "shad_struct.h"

t_scene	*scene_add_sphere(t_scene *scene, t_sphere *sphere,
			t_ubuffernode *parent, GLuint parent_slot)
{
	t_ubuffernode	*node;

	node = ubuffernode_new(shad_struct_get(SHAD_QUADRIC), sphere);
	ubufferlist_addnode(&scene->quadrics, node);
	if (parent)
		ubuffernode_bind(node, parent, parent_slot);
	ubuffernode_setdata(node);
	ubuffernode_subdata(node);
	return (scene);
}

t_scene	*scene_update_sphere(t_scene *scene, t_sphere *sphere)
{
	ubuffernode_subdata(ubufferlist_fetch_node(&scene->quadrics, sphere));
	return (scene);
}

t_scene	*scene_bind_sph2geo(t_scene *scene, t_sphere *sphere,
			t_geometry *geometry)
{
	t_ubuffernode	*sphere_node;
	t_ubuffernode	*geometry_node;

	sphere_node = ubufferlist_fetch_node(&scene->quadrics, sphere);
	geometry_node = ubufferlist_fetch_node(&scene->geometries, geometry);
	ubuffernode_bind(sphere_node, geometry_node, CONST_GEOMETRY_VALUE_SLOT);
	ubuffernode_setdata(sphere_node);
	ubuffernode_setdata(geometry_node);
	ubuffernode_subdata(sphere_node);
	ubuffernode_subdata(geometry_node);
	return (scene);
}
