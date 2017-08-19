/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 03:18:37 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/02/27 22:30:55 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "error.h"
#include "constants.h"
#include "shad_struct.h"
#include "context.h"

t_scene	*scene_init_cameras(t_scene *scene, t_context *context)
{
	ubufferlist_init(&scene->cameras, shad_struct_get(SHAD_CAMERA), context);
	return (scene);
}

t_scene	*scene_add_camera(t_scene *scene, t_camera *camera,
					t_ubuffernode *parent, GLuint parent_slot)
{
	t_ubuffernode	*node;

	node = ubuffernode_new(shad_struct_get(SHAD_CAMERA), camera);
	ubufferlist_addnode(&scene->cameras, node);
	if (parent)
		ubuffernode_bind(node, parent, parent_slot);
	ubuffernode_setdata(node);
	ubuffernode_subdata(node);
	scene->current_cam = node;
	return (scene);
}

t_scene	*scene_update_camera(t_scene *scene, t_camera *camera)
{
	ubuffernode_subdata(ubufferlist_fetch_node(&scene->cameras, camera));
	return (scene);
}
