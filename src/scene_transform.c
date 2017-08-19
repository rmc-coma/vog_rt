/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_transform.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 03:28:39 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/02/24 06:11:59 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "constants.h"
#include "context.h"

t_scene	*scene_init_transforms(t_scene *scene, t_context *context)
{
	ubufferlist_init(&scene->transforms, shad_struct_get(SHAD_TRANSFORM),
			context);
	return (scene);
}

t_scene	*scene_add_transform(t_scene *scene, t_transform *transform,
			t_ubuffernode *parent, GLuint parent_slot)
{
	t_ubuffernode	*node;

	node = ubuffernode_new(shad_struct_get(SHAD_TRANSFORM), transform);
	ubufferlist_addnode(&scene->transforms, node);
	if (parent)
		ubuffernode_bind(node, parent, parent_slot);
	transform_update_quaternion(transform);
	ubuffernode_setdata(node);
	ubuffernode_subdata(node);
	return (scene);
}

t_scene	*scene_update_transform(t_scene *scene, t_transform *transform)
{
	transform_update_quaternion(transform);
	ubuffernode_subdata(ubufferlist_fetch_node(&scene->transforms, transform));
	return (scene);
}

t_scene	*scene_bind_trs2obj(t_scene *scene, t_transform *transform,
			t_object *object)
{
	t_ubuffernode	*transform_node;
	t_ubuffernode	*object_node;

	object_node = ubufferlist_fetch_node(&scene->objects, object);
	transform_node = ubufferlist_fetch_node(&scene->transforms, transform);
	ubuffernode_bind(object_node, transform_node, 1);
	ubuffernode_setdata(transform_node);
	ubuffernode_setdata(object_node);
	ubuffernode_subdata(transform_node);
	ubuffernode_subdata(object_node);
	return (scene);
}
