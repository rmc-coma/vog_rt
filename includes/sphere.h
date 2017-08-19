/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 17:16:37 by calemany          #+#    #+#             */
/*   Updated: 2017/02/28 19:21:31 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# define CONST_SPHERE_VAR_SIZE(var)	(var <= 1 ? 4 : 0)

# include "quadric.h"
# include "libftxml.h"

typedef struct	s_sphere
{
	t_quadric	quadric;
	float		radius;
}				t_sphere;

t_sphere		*sphere_new(void);
t_sphere		*sphere_init(t_sphere *const sphere);
t_sphere		*sphere_update_quadric(t_sphere *s);
int				sphere_parse(t_sphere *sphere, t_xml_element const *elem);

#endif
