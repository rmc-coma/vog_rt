/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 19:13:52 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/08 17:34:45 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "libftxml.h"
# include "vector.h"
# include <SDL2/SDL.h>
# include "camera.h"

typedef struct	s_light
{
	float			intensity;
	float			angle;
	float			ambiant;
	t_vec3			pos;
	t_vec3			dir;
	t_vec3			color;
	int				parallel;
}				t_light;

t_light			*light_new(void);
t_light			*light_init(t_light *const light);
t_light			*light_update(t_light *light);
int				light_parse(t_light *light, t_xml_element const *elem);

t_light			*light_move_left(t_light *light, Uint32 frametime,
								t_camera *current);
t_light			*light_move_up(t_light *light, Uint32 frametime,
								t_camera *current);
t_light			*light_move_right(t_light *light, Uint32 frametime,
								t_camera *current);
t_light			*light_move_down(t_light *light, Uint32 frametime,
								t_camera *current);
t_light			*light_move_backward(t_light *light, Uint32 frametime,
								t_camera *current);
t_light			*light_move_forward(t_light *light, Uint32 frametime,
								t_camera *current);
t_light			*light_rotate_left(t_light *light, Uint32 frametime,
								t_camera *current);
t_light			*light_rotate_right(t_light *light, Uint32 frametime,
								t_camera *current);
t_light			*light_rotate_up(t_light *light, Uint32 frametime,
								t_camera *current);
t_light			*light_rotate_down(t_light *light, Uint32 frametime,
								t_camera *current);

#endif
