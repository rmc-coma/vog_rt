/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 01:28:53 by jleu              #+#    #+#             */
/*   Updated: 2017/03/01 01:29:20 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

const char	*geometry_name(t_geometry *const geometry)
{
	if (geometry->type == GEOMETRY_SPHERE)
		return ("sphere");
	else if (geometry->type == GEOMETRY_CYLINDER)
		return ("cylinder");
	else if (geometry->type == GEOMETRY_CONE)
		return ("cone");
	else if (geometry->type == GEOMETRY_PLANE)
		return ("plane");
	else if (geometry->type == GEOMETRY_TORUS)
		return ("torus");
	else if (geometry->type == GEOMETRY_BOX)
		return ("box");
	else if (geometry->type == GEOMETRY_MOBIUS)
		return ("mobius");
	else if (geometry->type == GEOMETRY_CUBIC)
		return ("cubic");
	else if (geometry->type == GEOMETRY_ELLIPSOID)
		return ("ellipsoid");
	else if (geometry->type == GEOMETRY_HYPERBOLOID)
		return ("hyperboloid");
	else if (geometry->type == GEOMETRY_PARABOLOID)
		return ("paraboloid");
	return ("");
}
