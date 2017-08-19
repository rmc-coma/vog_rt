/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_frame_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 01:31:59 by jleu              #+#    #+#             */
/*   Updated: 2017/03/13 18:03:01 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "parameters.h"
#include "libft.h"

t_gui	*gui_frame_init(t_gui *const gui)
{
	static int count = 1;

	ft_bzero((void *)(&gui->frame), sizeof(t_frame));
	gui->frame.width = GUI_FRAME_WIDTH;
	gui->frame.height = GUI_FRAME_HEIGHT;
	gui->frame.gl_surface_size = GUI_FRAME_WIDTH * GUI_FRAME_HEIGHT * 4;
	gui->frame.gl_surface = (GLuint *)ft_memalloc(gui->frame.gl_surface_size);
	gui->frame.pos = ivec2(GUI_FRAME_X_POS, GUI_FRAME_Y_POS);
	++count;
	return (gui);
}

int		gui_frame_create(t_gui *const gui)
{
	glGenBuffers(1, &gui->frame.gl_id);
	glBindBuffer(GL_TEXTURE_BUFFER, gui->frame.gl_id);
	glTexBuffer(GL_TEXTURE_BUFFER, GL_RGBA8, gui->frame.gl_id);
	glBufferData(GL_TEXTURE_BUFFER, gui->frame.gl_surface_size,
				(GLvoid *)gui->frame.gl_surface, GL_DYNAMIC_DRAW);
	glBindBuffer(GL_TEXTURE_BUFFER, 0);
	return (0);
}
