/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 17:28:43 by calemany          #+#    #+#             */
/*   Updated: 2017/02/28 18:31:40 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "libftxml.h"
# include "quadric.h"

typedef struct	s_cylinder
{
	t_quadric	quadric;
	float		radius;
}				t_cylinder;

t_cylinder		*cylinder_new(void);
t_cylinder		*cylinder_init(t_cylinder *const cylinder);
t_cylinder		*cylinder_update_quadric(t_cylinder *c);
int				cylinder_parse(t_cylinder *cylinder, t_xml_element const *elem);

#endif
