/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_box.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 03:31:54 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/02/27 22:30:31 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "constants.h"
#include "shad_struct.h"
#include "context.h"

t_scene	*scene_init_boxes(t_scene *scene, t_context *context)
{
	ubufferlist_init(&scene->boxes, shad_struct_get(SHAD_BOX), context);
	return (scene);
}

t_scene	*scene_add_box(t_scene *scene, t_box *box,
			t_ubuffernode *parent, GLuint parent_slot)
{
	t_ubuffernode	*node;

	node = ubuffernode_new(shad_struct_get(SHAD_BOX), box);
	ubufferlist_addnode(&scene->boxes, node);
	if (parent)
		ubuffernode_bind(node, parent, parent_slot);
	ubuffernode_setdata(node);
	ubuffernode_subdata(node);
	return (scene);
}

t_scene	*scene_update_box(t_scene *scene, t_box *box)
{
	ubuffernode_subdata(ubufferlist_fetch_node(&scene->boxes, box));
	return (scene);
}

t_scene	*scene_bind_box2geo(t_scene *scene, t_box *box,
			t_geometry *geometry)
{
	t_ubuffernode	*box_node;
	t_ubuffernode	*geometry_node;

	box_node = ubufferlist_fetch_node(&scene->boxes, box);
	geometry_node = ubufferlist_fetch_node(&scene->geometries, geometry);
	ubuffernode_bind(box_node, geometry_node, CONST_GEOMETRY_VALUE_SLOT);
	ubuffernode_setdata(box_node);
	ubuffernode_setdata(geometry_node);
	ubuffernode_subdata(box_node);
	ubuffernode_subdata(geometry_node);
	return (scene);
}
