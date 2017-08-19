/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_material.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 03:24:01 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/02/24 06:16:50 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "constants.h"
#include "context.h"

t_scene	*scene_init_materials(t_scene *scene, t_context *context)
{
	ubufferlist_init(&scene->materials, shad_struct_get(SHAD_MATERIAL),
			context);
	return (scene);
}

t_scene	*scene_add_material(t_scene *scene, t_material *material,
			t_ubuffernode *parent, GLuint parent_slot)
{
	t_ubuffernode	*node;

	node = ubuffernode_new(shad_struct_get(SHAD_MATERIAL), material);
	ubufferlist_addnode(&scene->materials, node);
	if (parent)
		ubuffernode_bind(node, parent, parent_slot);
	ubuffernode_setdata(node);
	ubuffernode_subdata(node);
	return (scene);
}

t_scene	*scene_update_material_buffer(t_scene *scene, t_material *material)
{
	ubuffernode_subdata(ubufferlist_fetch_node(&scene->materials, material));
	return (scene);
}

t_scene	*scene_bind_mat2msh(t_scene *scene, t_material *material,
			t_mesh *mesh)
{
	t_ubuffernode	*material_node;
	t_ubuffernode	*mesh_node;

	material_node = ubufferlist_fetch_node(&scene->materials, material);
	mesh_node = ubufferlist_fetch_node(&scene->meshes, mesh);
	ubuffernode_bind(material_node, mesh_node, CONST_MESH_MATERIAL_SLOT);
	ubuffernode_setdata(material_node);
	ubuffernode_setdata(mesh_node);
	ubuffernode_subdata(material_node);
	ubuffernode_subdata(mesh_node);
	return (scene);
}
