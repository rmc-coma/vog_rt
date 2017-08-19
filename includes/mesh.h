/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 15:37:45 by calemany          #+#    #+#             */
/*   Updated: 2017/02/28 18:52:04 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESH_H
# define MESH_H

# include "geometry.h"
# include "material.h"

# include "libftxml.h"

typedef struct	s_mesh
{
	t_geometry	*geometry;
	t_material	*material;
}				t_mesh;

t_mesh			*mesh_new(void);
t_mesh			*mesh_init(t_mesh *const mesh);
t_mesh			*mesh_set(t_mesh *const mesh, t_geometry *const geometry,
				t_material *const material);
int				mesh_parse(t_mesh *mesh, t_xml_element const *elem);
t_mesh			*mesh_destruct(t_mesh *mesh);

#endif
