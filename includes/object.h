/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 18:03:54 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/02/24 06:28:19 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "mesh.h"
# include "transform.h"
# include "light.h"

# include "libftxml.h"

typedef struct	s_object
{
	t_mesh		*mesh;
	t_transform	*transform;
}				t_object;

t_object		*object_new(void);
t_object		*object_init(t_object *const object);
t_object		*object_set(t_object *const object, t_mesh *const mesh,
		t_transform *const transform);

int				object_parse(t_object *obj, t_xml_element const *elem);
t_object		*object_destruct(t_object *object);

#endif
