/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 17:29:15 by calemany          #+#    #+#             */
/*   Updated: 2017/02/28 18:26:52 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONE_H
# define CONE_H

# include "libftxml.h"
# include "quadric.h"

typedef struct	s_cone
{
	t_quadric	quadric;
	float		angle;
}				t_cone;

t_cone			*cone_new(void);
t_cone			*cone_init(t_cone *const cone);
t_cone			*cone_update(t_cone *cone);
int				cone_parse(t_cone *cone, t_xml_element const *elem);

#endif
