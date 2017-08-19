/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 03:23:01 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/02/27 22:32:24 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "constants.h"
#include "shad_struct.h"
#include "context.h"

t_scene	*scene_init_lights(t_scene *scene, t_context *context)
{
	ubufferlist_init(&scene->lights, shad_struct_get(SHAD_LIGHT), context);
	return (scene);
}

t_scene	*scene_add_light(t_scene *scene, t_light *light,
			t_ubuffernode *parent, GLuint parent_slot)
{
	t_ubuffernode	*node;

	node = ubuffernode_new(shad_struct_get(SHAD_LIGHT), light);
	ubufferlist_addnode(&scene->lights, node);
	if (parent)
		ubuffernode_bind(node, parent, parent_slot);
	ubuffernode_setdata(node);
	ubuffernode_subdata(node);
	return (scene);
}

t_scene	*scene_update_light(t_scene *scene, t_light *light)
{
	ubuffernode_subdata(ubufferlist_fetch_node(&scene->lights, light));
	return (scene);
}
