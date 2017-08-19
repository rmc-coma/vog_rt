/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 19:21:57 by jleu              #+#    #+#             */
/*   Updated: 2017/02/28 19:22:16 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TORUS_H
# define TORUS_H

# include "libftxml.h"
# include "vector.h"

typedef struct		s_torus
{
	float			major_radius;
	float			minor_radius;
}					t_torus;

t_torus				*torus_new(void);
t_torus				*torus_init(t_torus *torus);
void				torus_get_aabb(t_torus const *torus,
					t_vec3 *min, t_vec3 *max);
int					torus_parse(t_torus *torus, t_xml_element const *elem);

#endif
