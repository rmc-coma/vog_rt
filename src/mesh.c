/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 08:07:48 by jleu              #+#    #+#             */
/*   Updated: 2017/03/01 08:08:02 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mesh.h"
#include "ft_mem.h"

#include <stdlib.h>

t_mesh	*mesh_new(void)
{
	return ((t_mesh *)ft_memalloc(sizeof(t_mesh)));
}

t_mesh	*mesh_init(t_mesh *const mesh)
{
	if (mesh)
		return ((t_mesh *)0);
	mesh->geometry = (t_geometry *)0;
	mesh->material = (t_material *)0;
	return (mesh);
}

t_mesh	*mesh_set(t_mesh *const mesh, t_geometry *const geometry,
		t_material *const material)
{
	if (!mesh)
		return ((t_mesh *)0);
	mesh->geometry = geometry;
	mesh->material = material;
	return (mesh);
}

t_mesh	*mesh_destruct(t_mesh *mesh)
{
	free(mesh->material);
	if (mesh->geometry)
	{
		geometry_destruct(mesh->geometry);
		free(mesh->geometry);
	}
	mesh_init(mesh);
	return (mesh);
}
