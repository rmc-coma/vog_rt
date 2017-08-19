/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_init2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 05:00:14 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/02/06 05:04:25 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "constants.h"
#include "error.h"

static t_gui	*gui_vao_init2(t_gui *const gui)
{
	gui->gl_frametexture_loc = glGetUniformLocation(gui->gpu_program.gl_id,
		CONST_GUI_FRAMETEXTURE_SHADER_VARNAME);
	gui->frame.gl_surface_location = glGetUniformLocation(
		gui->gpu_program.gl_id, CONST_GUI_FRAME_SHADER_VARNAME);
	glUniform1i(gui->gl_frametexture_loc, 0);
	glUniform1i(gui->frame.gl_surface_location, 1);
	glValidateProgram(gui->gpu_program.gl_id);
	if (error_check_program(&gui->gpu_program, GL_VALIDATE_STATUS) !=
		NO_ERROR)
		error_put_from_struct(&gui->gpu_program.error);
	gui->win_width_location = glGetUniformLocation(gui->gpu_program.gl_id,
		CONST_GUI_WINDOW_WIDTH_SHADER_VARNAME);
	gui->win_height_location = glGetUniformLocation(gui->gpu_program.gl_id,
		CONST_GUI_WINDOW_HEIGHT_SHADER_VARNAME);
	gui->frame.width_location = glGetUniformLocation(gui->gpu_program.gl_id,
		CONST_GUI_FRAME_WIDTH_SHADER_VARNAME);
	gui->frame.height_location = glGetUniformLocation(gui->gpu_program.gl_id,
		CONST_GUI_FRAME_HEIGHT_SHADER_VARNAME);
	gui->frame.pos_location = glGetUniformLocation(gui->gpu_program.gl_id,
		CONST_GUI_FRAME_POS_SHADER_VARNAME);
	gui->context_width_location = glGetUniformLocation(gui->gpu_program.gl_id,
		CONST_GUI_CONTEXT_WIDTH_SHADER_VARNAME);
	gui->context_height_location = glGetUniformLocation(gui->gpu_program.gl_id,
		CONST_GUI_CONTEXT_HEIGHT_SHADER_VARNAME);
	return (gui);
}

t_gui			*gui_vao_init(t_gui *const gui)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glGenVertexArrays(1, &gui->vao_id);
	glBindVertexArray(gui->vao_id);
	glBindBuffer(GL_ARRAY_BUFFER, gui->vbo_id);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glUseProgram(gui->gpu_program.gl_id);
	glBindVertexArray(gui->vao_id);
	gui_vao_init2(gui);
	glBindVertexArray(0);
	glUseProgram(0);
	return (gui);
}
