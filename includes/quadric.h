/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadric.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 19:19:21 by jleu              #+#    #+#             */
/*   Updated: 2017/02/28 19:36:13 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUADRIC_H
# define QUADRIC_H

# include "vector.h"

/*
** Represents an equation of the form ax^2 + by^2 + cz^2 = d
*/

typedef struct	s_quadric
{
	float		a;
	float		b;
	float		c;
	float		d;
	t_vec3		size;
}				t_quadric;

t_quadric		*quadric_init(t_quadric *q);
int				quadric_parse(t_quadric *q, t_xml_element const *elem);
void			quadric_get_aabb(t_quadric const *q,
		t_vec3 *min, t_vec3 *max);

#endif
