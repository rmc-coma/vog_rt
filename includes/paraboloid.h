/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paraboloid.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 19:16:47 by jleu              #+#    #+#             */
/*   Updated: 2017/02/28 19:17:10 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARABOLOID_H
# define PARABOLOID_H

# include "quadric.h"
# include "libftxml.h"

typedef struct	s_paraboloid
{
	t_quadric	quadric;
	float		radius_x;
	float		radius_z;
}				t_paraboloid;

t_paraboloid	*paraboloid_new(void);
t_paraboloid	*paraboloid_init(t_paraboloid *const paraboloid);
t_paraboloid	*paraboloid_update_quadric(t_paraboloid *s);
int				paraboloid_parse(t_paraboloid *paraboloid,
				t_xml_element const *elem);

#endif
