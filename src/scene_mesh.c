/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_mesh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 03:25:05 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/02/27 22:32:37 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "constants.h"
#include "shad_struct.h"
#include "context.h"

t_scene	*scene_init_meshes(t_scene *scene, t_context *context)
{
	ubufferlist_init(&scene->meshes, shad_struct_get(SHAD_MESH), context);
	return (scene);
}

t_scene	*scene_add_mesh(t_scene *scene, t_mesh *mesh,
			t_ubuffernode *parent, GLuint parent_slot)
{
	t_ubuffernode	*node;

	node = ubuffernode_new(shad_struct_get(SHAD_MESH), mesh);
	ubufferlist_addnode(&scene->meshes, node);
	if (parent)
		ubuffernode_bind(node, parent, parent_slot);
	if (mesh->geometry)
		scene_add_geometry(scene, mesh->geometry, node,
				CONST_MESH_GEOMETRY_SLOT);
	if (mesh->material)
		scene_add_material(scene, mesh->material, node,
				CONST_MESH_MATERIAL_SLOT);
	ubuffernode_setdata(node);
	ubuffernode_subdata(node);
	return (scene);
}

t_scene	*scene_update_mesh(t_scene *scene, t_mesh *mesh)
{
	ubuffernode_subdata(ubufferlist_fetch_node(&scene->meshes, mesh));
	return (scene);
}

t_scene	*scene_bind_msh2obj(t_scene *scene, t_mesh *mesh,
			t_object *object)
{
	t_ubuffernode	*mesh_node;
	t_ubuffernode	*object_node;

	mesh_node = ubufferlist_fetch_node(&scene->meshes, mesh);
	object_node = ubufferlist_fetch_node(&scene->objects, object);
	ubuffernode_bind(mesh_node, object_node, CONST_OBJECT_MESH_SLOT);
	ubuffernode_setdata(mesh_node);
	ubuffernode_setdata(object_node);
	ubuffernode_subdata(mesh_node);
	ubuffernode_subdata(object_node);
	return (scene);
}
