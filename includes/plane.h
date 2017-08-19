/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 17:28:14 by calemany          #+#    #+#             */
/*   Updated: 2017/02/28 19:18:42 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

# include "vector.h"
# include "libftxml.h"

typedef struct	s_plane
{
	t_vec3		size;
}				t_plane;

t_plane			*plane_new(void);
t_plane			*plane_init(t_plane *const plane);
void			plane_get_aabb(t_plane const *plane, t_vec3 *min, t_vec3 *max);
int				plane_parse(t_plane *plane, t_xml_element const *elem);

#endif
