/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 02:30:49 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/13 18:02:15 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "error.h"
#include "debug.h"
#include "parameters.h"
#include "constants.h"
#include "libft.h"
#include "utils.h"
#include <stdlib.h>

int		gui_init(t_gui *const gui, t_context *const context,
			GLint *const window_width, GLint *const window_height)
{
	ft_bzero((void *)gui, sizeof(t_gui));
	gui->win_width = window_width;
	gui->win_height = window_height;
	gui->context_width = &context->width;
	gui->context_height = &context->height;
	gui->frame.width = GUI_FRAME_WIDTH;
	gui->frame.height = GUI_FRAME_HEIGHT;
	gui->frame.pos = ivec2(GUI_FRAME_X_POS, GUI_FRAME_Y_POS);
	return (0);
}

int		gui_create(t_gui *const gui, t_context *const context,
			char const *exec_filename)
{
	t_img	tmp;

	img_glprep(img_parse(&tmp, GUI_FONT_PATH));
	gui->font = (GLuint *)(tmp.value.bmp->data);
	gui->fontdata.width = tmp.value.bmp->width;
	gui->fontdata.height = tmp.value.bmp->height;
	gui->fontdata.letter_width = tmp.value.bmp->width / FONT_N_CHARS;
	if (gui_program_init(gui, exec_filename) != NO_ERROR)
		return (-1);
	gui_vbo_init(gui);
	gui_vao_init(gui);
	glGenTextures(1, &gui->gl_frametexture);
	glBindTexture(GL_TEXTURE_2D, gui->gl_frametexture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, context->width, context->height, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, 0);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glBindTexture(GL_TEXTURE_2D, 0);
	glBindFramebuffer(GL_FRAMEBUFFER, context->gl_framebuffer);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D,
		gui->gl_frametexture, 0);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	gui_frame_create(gui);
	return (0);
}

int		gui_program_init(t_gui *const gui, const char *const exec_filename)
{
	char	*path;
	int		err;

	gui->exec_dir = set_exec_dir(gui->exec_dir, exec_filename);
	path = ft_strjoin(gui->exec_dir, SHADER_GUI_VERTEX_PATH);
	err = shader_prepare(&gui->vert_shader, path, GL_VERTEX_SHADER);
	free(path);
	if (err != NO_ERROR)
		error_put_from_struct(&gui->vert_shader.error);
	path = ft_strjoin(gui->exec_dir, SHADER_GUI_FRAGMENT_PATH);
	err = shader_prepare(&gui->frag_shader, path, GL_FRAGMENT_SHADER);
	free(path);
	if (err != NO_ERROR)
		error_put_from_struct(&gui->frag_shader.error);
	if (program_prepare(&gui->gpu_program, &gui->vert_shader,
		&gui->frag_shader) != NO_ERROR)
		error_put_from_struct(&gui->gpu_program.error);
	return (err);
}

t_gui	*gui_vbo_init(t_gui *const gui)
{
	GLfloat array[12];

	array[0] = -1.0f;
	array[1] = -1.0f;
	array[2] = -1.0f;
	array[3] = 1.0f;
	array[4] = 1.0f;
	array[5] = -1.0f;
	array[6] = 1.0f;
	array[7] = 1.0f;
	array[8] = 1.0f;
	array[9] = -1.0f;
	array[10] = -1.0f;
	array[11] = 1.0f;
	glGenBuffers(1, &gui->vbo_id);
	glBindBuffer(GL_ARRAY_BUFFER, gui->vbo_id);
	glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(GLfloat), 0, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, 12 * sizeof(GLfloat), &array[0]);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	return (gui);
}
