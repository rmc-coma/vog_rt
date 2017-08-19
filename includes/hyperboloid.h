/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hyperboloid.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 19:35:35 by jleu              #+#    #+#             */
/*   Updated: 2017/02/28 19:44:15 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HYPERBOLOID_H
# define HYPERBOLOID_H

# include "quadric.h"

# include "libftxml.h"

/*
** Represents an hyperboloid surface.
** x^2/a^2 - y^2/b^2 + z^2/c^2 = d
*/

typedef struct		s_hyperboloid
{
	t_quadric		quadric;
	float			a;
	float			b;
	float			c;
	float			d;
}					t_hyperboloid;

t_hyperboloid		*hyperboloid_new(void);
t_hyperboloid		*hyperboloid_init(t_hyperboloid *hyperboloid);
t_hyperboloid		*hyperboloid_update_quadric(t_hyperboloid *h);
int					hyperboloid_parse(t_hyperboloid *h,
		t_xml_element const *elem);

#endif
