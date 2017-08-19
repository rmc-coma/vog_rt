/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_geometry.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 03:21:24 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/01 07:40:21 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "constants.h"
#include "context.h"

#define FC(func) (void *(*)(void *, void *, void *, GLuint))(func)

/*
**	replace GEOMETRY_TYPE_COUNT by his value for norme
*/

static void	add_branch(t_scene *scene, t_geometry *geometry,
	t_ubuffernode *node)
{
	int						i;
	static t_geometry_type	types[11] = {
		GEOMETRY_SPHERE, GEOMETRY_CYLINDER, GEOMETRY_CONE, GEOMETRY_PLANE,
		GEOMETRY_BOX, GEOMETRY_HYPERBOLOID, GEOMETRY_MOBIUS,
		GEOMETRY_ELLIPSOID, GEOMETRY_TORUS, GEOMETRY_PARABOLOID, GEOMETRY_CUBIC
	};
	static void				*(*funcs[11])(void *, void *, void *, GLuint) = {
		FC(scene_add_sphere), FC(scene_add_cylinder), FC(scene_add_cone),
		FC(scene_add_plane), FC(scene_add_box), FC(scene_add_hyperboloid),
		FC(scene_add_mobius), FC(scene_add_ellipsoid), FC(scene_add_torus),
		FC(scene_add_paraboloid), FC(scene_add_cubic)
	};

	i = 0;
	while (geometry->type != types[i])
		if (++i > GEOMETRY_TYPE_COUNT)
			return ;
	funcs[i](scene, geometry->value.setter, node, CONST_GEOMETRY_VALUE_SLOT);
}

t_scene		*scene_init_geometries(t_scene *scene, t_context *context)
{
	ubufferlist_init(&scene->geometries, shad_struct_get(SHAD_GEOMETRY),
			context);
	return (scene);
}

t_scene		*scene_add_geometry(t_scene *scene, t_geometry *geometry,
				t_ubuffernode *parent, GLuint parent_slot)
{
	t_ubuffernode	*node;

	node = ubuffernode_new(shad_struct_get(SHAD_GEOMETRY), geometry);
	ubufferlist_addnode(&scene->geometries, node);
	if (parent)
		ubuffernode_bind(node, parent, parent_slot);
	if (geometry->type && geometry->value.setter)
		add_branch(scene, geometry, node);
	ubuffernode_setdata(node);
	ubuffernode_subdata(node);
	return (scene);
}

t_scene		*scene_update_geometry(t_scene *scene, t_geometry *geometry)
{
	ubuffernode_subdata(ubufferlist_fetch_node(&scene->geometries, geometry));
	return (scene);
}

t_scene		*scene_bind_geo2msh(t_scene *scene, t_geometry *geometry,
							t_mesh *mesh)
{
	t_ubuffernode	*geometry_node;
	t_ubuffernode	*mesh_node;

	ubuffernode_bind((geometry_node = ubufferlist_fetch_node(&scene->geometries,
					geometry)),
					(mesh_node = ubufferlist_fetch_node(&scene->meshes, mesh)),
					CONST_MESH_GEOMETRY_SLOT);
	ubuffernode_setdata(geometry_node);
	ubuffernode_setdata(mesh_node);
	ubuffernode_subdata(geometry_node);
	ubuffernode_subdata(mesh_node);
	return (scene);
}
