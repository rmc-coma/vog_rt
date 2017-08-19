/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ellipsoid.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 18:32:40 by jleu              #+#    #+#             */
/*   Updated: 2017/02/28 18:35:26 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELLIPSOID_H
# define ELLIPSOID_H

# define CONST_ELLIPSOID_VAR_SIZE(var)	(var <= 3 ? 4 : 0)

# include "quadric.h"
# include "libftxml.h"

typedef struct	s_ellipsoid
{
	t_quadric	quadric;
	float		radius_x;
	float		radius_y;
	float		radius_z;
}				t_ellipsoid;

t_ellipsoid		*ellipsoid_new(void);
t_ellipsoid		*ellipsoid_init(t_ellipsoid *const ellipsoid);
t_ellipsoid		*ellipsoid_update_quadric(t_ellipsoid *s);
int				ellipsoid_parse(t_ellipsoid *ellipsoid,
								t_xml_element const *elem);

#endif
