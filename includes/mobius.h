/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mobius.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 18:52:15 by jleu              #+#    #+#             */
/*   Updated: 2017/02/28 18:52:50 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOBIUS_H
# define MOBIUS_H

# include "libftxml.h"
# include "vector.h"

typedef struct		s_mobius
{
	float			radius;
	float			width;
}					t_mobius;

t_mobius			*mobius_new(void);
t_mobius			*mobius_init(t_mobius *m);
int					mobius_parse(t_mobius *mobius, t_xml_element const *elem);
void				mobius_get_aabb(t_mobius const *mobius,
					t_vec3 *min, t_vec3 *max);

#endif
