/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shad_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 01:57:44 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/03 15:26:06 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shad_struct.h"
#include <stdlib.h>
#define SIZES_CAMERA {4, 4, 4, 12, 4, 12, 4, 12, 12}
#define SIZES_OBJECT {4, 4, 4}
#define SIZES_TRANS {4, 12, 12, 12, 16}
#define SIZES_LIGHT {4, 4, 4, 4, 12, 12, 12, 4}
#define SIZES_MESH {4, 4, 4}
#define SIZES_GEO {4, 4, 4, 12, 12}
#define SIZES_QUADRIC {4, 4, 4, 4, 4, 12}
#define SIZES_PLANE	{4, 12}
#define SIZES_MATERIAL {4, 4, 4, 4, 4, 4, 4, 4, 12}
#define SIZES_TORUS {4, 4, 4}
#define SIZES_BOX {4, 12}
#define SIZES_MOBIUS {4, 4, 4}
#define SIZES_CUB 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4

t_shad_struct const		*shad_struct_get(t_shad_struct_type type)
{
	static const t_shad_struct	structs[SHAD_STRUCT_COUNT] =
	{[SHAD_CAMERA] = {0, "cameras", "n_cameras", 0, 0, 9, SIZES_CAMERA},
	[SHAD_OBJECT] = {1, "objects", "n_objects", 0, 2, 3, SIZES_OBJECT},
	[SHAD_TRANSFORM] = {2, "transforms", "n_transforms", 0, 0, 5, SIZES_TRANS},
	[SHAD_LIGHT] = {3, "lights", "n_lights", 0, 0, 8, SIZES_LIGHT},
	[SHAD_MESH] = {4, "meshes", "n_meshes", 0, 2, 3, SIZES_MESH},
	[SHAD_GEOMETRY] = {5, "geometries", "n_geometries", 1, 1, 5, SIZES_GEO},
	[SHAD_QUADRIC] = {6, "quadrics", "n_quadrics", 0, 0, 7, SIZES_QUADRIC},
	[SHAD_PLANE] = {7, "planes", "n_planes", 0, 0, 2, SIZES_PLANE},
	[SHAD_MATERIAL] = {8, "materials", "n_materials", 0, 0, 9, SIZES_MATERIAL},
	[SHAD_TORUS] = {9, "tori", "n_tori", 0, 0, 3, SIZES_TORUS},
	[SHAD_BOX] = {10, "boxes", "n_boxes", 0, 0, 2, SIZES_BOX},
	[SHAD_MOBIUS] = {11, "mobiuses", "n_mobiuses", 0, 0, 3, SIZES_MOBIUS},
	[SHAD_CUBIC] = {12, "cubics", "n_cubics", 0, 0, 23, {4, 12, SIZES_CUB}}};

	return (&structs[type]);
}
