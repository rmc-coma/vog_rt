/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 23:50:40 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/01 01:33:10 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

#include <stdio.h>

t_gui	*gui_draw(t_gui *const gui)
{
	glViewport(gui->frame.pos.x, gui->frame.pos.y,
		gui->frame.width, gui->frame.height);
	glUseProgram(gui->gpu_program.gl_id);
	glBindVertexArray(gui->vao_id);
	glUniform1i(gui->frame.width_location, gui->frame.width);
	glUniform1i(gui->frame.height_location, gui->frame.height);
	glUniform1iv(gui->frame.pos_location, 2, (GLint *)(&gui->frame.pos.x));
	glUniform1i(gui->win_width_location, *(gui->win_width));
	glUniform1i(gui->win_height_location, *(gui->win_height));
	glUniform1i(gui->gl_frametexture_loc, 0);
	glUniform1i(gui->frame.gl_surface_location, 1);
	glUniform1i(gui->context_width_location, *(gui->context_width));
	glUniform1i(gui->context_height_location, *(gui->context_height));
	glBindTexture(GL_TEXTURE_2D, gui->gl_frametexture);
	glBindBuffer(GL_TEXTURE_BUFFER, gui->frame.gl_id);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindBuffer(GL_TEXTURE_BUFFER, 0);
	glBindTexture(GL_TEXTURE_2D, 0);
	glBindVertexArray(0);
	glDisableVertexAttribArray(0);
	glUseProgram(0);
	return (gui);
}

t_bool	gui_is_on(t_gui *const gui, t_ivec2 *const pos)
{
	return (pos->x >= gui->frame.pos.x &&
		pos->x <= gui->frame.pos.x + gui->frame.width &&
		pos->y >= gui->frame.pos.y &&
		pos->y <= gui->frame.pos.y + gui->frame.height ?
		(char)1 : (char)0);
}
