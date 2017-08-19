/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 15:37:11 by calemany          #+#    #+#             */
/*   Updated: 2017/02/28 18:44:46 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_H
# define GEOMETRY_H

# include "sphere.h"
# include "ellipsoid.h"
# include "paraboloid.h"
# include "plane.h"
# include "cone.h"
# include "cylinder.h"
# include "torus.h"
# include "box.h"
# include "mobius.h"
# include "hyperboloid.h"
# include "cubic.h"
# include "vector.h"

# include "libftxml.h"

# define GEOMETRY_QUADRIC 0x1

typedef enum			e_geometry_type
{
	GEOMETRY_EMPTY = 0,
	GEOMETRY_SPHERE = 0xBA110001,
	GEOMETRY_CYLINDER = 0xC0C00001,
	GEOMETRY_CONE = 0x700B0001,
	GEOMETRY_PLANE = 0xF1A70000,
	GEOMETRY_TORUS = 0xBA9E1000,
	GEOMETRY_BOX = 0xAABB0000,
	GEOMETRY_MOBIUS = 0xB2000000,
	GEOMETRY_ELLIPSOID = 0x11111111,
	GEOMETRY_HYPERBOLOID = 0xB0100001,
	GEOMETRY_PARABOLOID = 0x12345679,
	GEOMETRY_CUBIC = 0xCBC00000,
	GEOMETRY_TYPE_COUNT = 11
}						t_geometry_type;

typedef	union			u_geometry_union
{
	t_sphere			*sphere;
	t_ellipsoid			*ellipsoid;
	t_plane				*plane;
	t_cylinder			*cylinder;
	t_cone				*cone;
	t_hyperboloid		*hyperboloid;
	t_paraboloid		*paraboloid;
	t_torus				*torus;
	t_box				*box;
	t_mobius			*mobius;
	t_cubic				*cubic;
	void				*setter;
}						t_geometry_union;

typedef struct			s_geometry
{
	t_geometry_type		type;
	t_geometry_union	value;
	t_vec3				min;
	t_vec3				max;
}						t_geometry;

t_geometry				*geometry_new(void);
t_geometry				*geometry_init(t_geometry *const geometry);
t_geometry				*geometry_set(t_geometry *const geometry,
									const t_geometry_type type,
									void *const value);
int						geometry_parse(t_geometry *geo,
									t_xml_element const *elem);
t_geometry				*geometry_destruct(t_geometry *geometry);
void					geometry_update_aabb(t_geometry *geometry);
const char				*geometry_name(t_geometry *const geometry);

#endif
