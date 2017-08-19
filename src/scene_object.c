/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 03:20:26 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/02/27 22:32:49 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "constants.h"
#include "shad_struct.h"
#include "context.h"

t_scene	*scene_init_objects(t_scene *scene, t_context *context)
{
	ubufferlist_init(&scene->objects, shad_struct_get(SHAD_OBJECT), context);
	return (scene);
}

t_scene	*scene_add_object(t_scene *scene, t_object *object,
		t_ubuffernode *parent, GLuint parent_slot)
{
	t_ubuffernode	*node;

	node = ubuffernode_new(shad_struct_get(SHAD_OBJECT), object);
	ubufferlist_addnode(&scene->objects, node);
	if (parent)
		ubuffernode_bind(node, parent, parent_slot);
	if (object->mesh)
		scene_add_mesh(scene, object->mesh, node, CONST_OBJECT_MESH_SLOT);
	if (object->transform)
		scene_add_transform(scene, object->transform, node,
				CONST_OBJECT_TRANSFORM_SLOT);
	ubuffernode_setdata(node);
	ubuffernode_subdata(node);
	return (scene);
}

t_scene	*scene_update_object(t_scene *scene, t_object *object)
{
	ubuffernode_subdata(ubufferlist_fetch_node(&scene->objects, object));
	return (scene);
}
