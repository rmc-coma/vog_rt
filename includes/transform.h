/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 17:48:42 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/02/28 19:23:29 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM_H
# define TRANSFORM_H

# include "vector.h"
# include "libftxml.h"
# include <SDL2/SDL.h>

typedef struct	s_transform
{
	t_vec3	pos;
	t_vec3	rot;
	t_vec3	scl;
	t_vec4	qtn;
}				t_transform;

t_transform		*transform_new(void);
t_transform		*transform_init(t_transform *const transform);
t_transform		*transform_update_quaternion(t_transform *const transform);
void			transform_apply(t_transform *const t, t_vec3 *v);
int				transform_parse(t_transform *transform,
				t_xml_element const *elem);
t_transform		*transform_move_forward(t_transform *transform,
				Uint32 frametime, t_camera *current);
t_transform		*transform_move_backward(t_transform *transform,
				Uint32 frametime, t_camera *current);
t_transform		*transform_move_left(t_transform *transform,
				Uint32 frametime, t_camera *current);
t_transform		*transform_move_right(t_transform *transform,
				Uint32 frametime, t_camera *current);
t_transform		*transform_move_up(t_transform *transform,
				Uint32 frametime, t_camera *current);
t_transform		*transform_move_down(t_transform *transform,
				Uint32 frametime, t_camera *current);
t_transform		*transform_rotate_forward(t_transform *transform,
				Uint32 frametime);
t_transform		*transform_rotate_backward(t_transform *transform,
				Uint32 frametime);
t_transform		*transform_rotate_left(t_transform *transform,
				Uint32 frametime);
t_transform		*transform_rotate_right(t_transform *transform,
				Uint32 frametime);
t_transform		*transform_rotate_up(t_transform *transform,
				Uint32 frametime);
t_transform		*transform_rotate_down(t_transform *transform,
				Uint32 frametime);

#endif
