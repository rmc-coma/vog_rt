/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 14:25:59 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/02/28 19:25:39 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include <SDL2/SDL.h>
# include "vector.h"
# include "gui.h"
# include "context.h"
# include "libftxml.h"
# include "xml_parsing.h"

typedef struct	s_window
{
	SDL_Window		*sdl_ptr;
	char			*title;
	GLint			width;
	GLint			height;
	t_ivec2			pos;
	Uint32			flags;
	t_context		context;
	t_gui			gui;
	unsigned char	mouse_capture;
	unsigned char	cursor_hidden;
}				t_window;

t_window		*window_init(t_window *const window);
int				window_parse(t_window *window, t_xml_element const *elem);
t_window		*window_create(t_window *const window);
void			window_vsync_switch(void);
void			window_showcursor_switch(void);

#endif
