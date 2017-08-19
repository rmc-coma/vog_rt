/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 18:13:52 by calemany          #+#    #+#             */
/*   Updated: 2017/03/08 18:23:46 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "vector.h"
# include <SDL2/SDL.h>
# include "libftxml.h"

typedef struct	s_camera
{
	float	near;
	float	fov;
	t_vec3	pos;
	float	phi;
	t_vec3	dir;
	float	theta;
	t_vec3	up;
	t_vec3	right;
}				t_camera;

t_camera		*camera_new(void);
t_camera		*camera_init(t_camera *camera);
t_camera		*camera_update(t_camera *camera);
t_camera		*camera_move_forward(t_camera *camera,
									Uint32 frametime, t_camera *current);
t_camera		*camera_move_backward(t_camera *camera,
									Uint32 frametime, t_camera *current);
t_camera		*camera_move_right(t_camera *camera,
									Uint32 frametime, t_camera *current);
t_camera		*camera_move_left(t_camera *camera,
									Uint32 frametime, t_camera *current);
t_camera		*camera_move_up(t_camera *camera,
									Uint32 frametime, t_camera *current);
t_camera		*camera_move_down(t_camera *camera,
									Uint32 frametime, t_camera *current);
t_camera		*camera_rotate_up(t_camera *camera,
									Uint32 frametime, t_camera *current);
t_camera		*camera_rotate_down(t_camera *camera,
									Uint32 frametime, t_camera *current);
t_camera		*camera_rotate_left(t_camera *camera,
									Uint32 frametime, t_camera *current);
t_camera		*camera_rotate_right(t_camera *camera,
									Uint32 frametime, t_camera *current);
int				camera_parse(t_camera *camera, t_xml_element const *elem);

#endif
