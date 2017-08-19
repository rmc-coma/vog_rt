/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 18:26:30 by jleu              #+#    #+#             */
/*   Updated: 2017/02/28 18:26:40 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOX_H
# define BOX_H

# include "vector.h"
# include "libftxml.h"

typedef struct	s_box
{
	t_vec3		size;
}				t_box;

t_box			*box_new(void);
t_box			*box_init(t_box *const box);
int				box_parse(t_box *box, t_xml_element const *elem);
void			box_get_aabb(t_box const *box, t_vec3 *min, t_vec3 *max);

#endif
