/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_torus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 03:30:10 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/02/24 06:12:58 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "constants.h"
#include "torus.h"
#include "shad_struct.h"
#include "context.h"

t_scene	*scene_init_tori(t_scene *scene, t_context *context)
{
	ubufferlist_init(&scene->tori, shad_struct_get(SHAD_TORUS), context);
	return (scene);
}

t_scene	*scene_add_torus(t_scene *scene, t_torus *torus,
			t_ubuffernode *parent, GLuint parent_slot)
{
	t_ubuffernode	*node;

	node = ubuffernode_new(shad_struct_get(SHAD_TORUS), torus);
	ubufferlist_addnode(&scene->tori, node);
	if (parent)
		ubuffernode_bind(node, parent, parent_slot);
	ubuffernode_setdata(node);
	ubuffernode_subdata(node);
	return (scene);
}

t_scene	*scene_update_torus(t_scene *scene, t_torus *torus)
{
	ubuffernode_subdata(ubufferlist_fetch_node(&scene->tori, torus));
	return (scene);
}

t_scene	*scene_bind_tor2geo(t_scene *scene, t_torus *torus,
			t_geometry *geometry)
{
	t_ubuffernode	*torus_node;
	t_ubuffernode	*geometry_node;

	torus_node = ubufferlist_fetch_node(&scene->tori, torus);
	geometry_node = ubufferlist_fetch_node(&scene->geometries, geometry);
	ubuffernode_bind(torus_node, geometry_node, CONST_GEOMETRY_VALUE_SLOT);
	ubuffernode_setdata(torus_node);
	ubuffernode_setdata(geometry_node);
	ubuffernode_subdata(torus_node);
	ubuffernode_subdata(geometry_node);
	return (scene);
}
