/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 05:49:19 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/01 01:14:25 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context.h"
#include "parameters.h"
#include "constants.h"
#include "error.h"
#include "debug.h"
#include "libft.h"
#include "utils.h"
#include <stdlib.h>

t_context	*context_init(t_context *const context)
{
	ft_bzero((void *)context, sizeof(t_context));
	context->width = CONTEXT_WIDTH;
	context->height = CONTEXT_HEIGHT;
	context->pos = ivec2(CONTEXT_X_POS, CONTEXT_Y_POS);
	context->ratio = (float)((float)CONTEXT_WIDTH / (float)CONTEXT_HEIGHT);
	context->render = 1;
	return (context);
}

int			context_create(t_context *const context, char const *exec_filename)
{
	if (context_program_init(context, exec_filename) != NO_ERROR)
		return (-1);
	context_vbo_init(context);
	context_vao_init(context);
	glGenFramebuffers(1, &context->gl_framebuffer);
	return (0);
}

t_context	*context_vbo_init(t_context *const context)
{
	GLfloat	array[12];

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
	glGenBuffers(1, &context->vbo_id);
	glBindBuffer(GL_ARRAY_BUFFER, context->vbo_id);
	glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(GLfloat), 0, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, 12 * sizeof(GLfloat), &array[0]);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	return (context);
}

t_context	*context_vao_init(t_context *const context)
{
	glGenVertexArrays(1, &context->vao_id);
	glBindVertexArray(context->vao_id);
	glBindBuffer(GL_ARRAY_BUFFER, context->vbo_id);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glUseProgram(context->gpu_program.gl_id);
	glBindVertexArray(context->vao_id);
	glValidateProgram(context->gpu_program.gl_id);
	if (error_check_program(&context->gpu_program, GL_VALIDATE_STATUS) !=
		NO_ERROR)
		error_put_from_struct(&context->gpu_program.error);
	context->ratio_location = glGetUniformLocation(context->gpu_program.gl_id,
								CONST_CONTEXT_RATIO_SHADER_VARNAME);
	glBindVertexArray(0);
	glUseProgram(0);
	return (context);
}

int			context_program_init(t_context *const context,
			char const *exec_filename)
{
	char	*path;
	int		err;

	context->exec_dir = set_exec_dir(context->exec_dir, exec_filename);
	path = ft_strjoin(context->exec_dir, SHADER_CONTEXT_VERTEX_PATH);
	err = shader_prepare(&context->vert_shader, path, GL_VERTEX_SHADER);
	free(path);
	if (err != NO_ERROR)
		error_put_from_struct(&context->vert_shader.error);
	path = ft_strjoin(context->exec_dir, SHADER_CONTEXT_FRAGMENT_PATH);
	err = shader_prepare(&context->frag_shader, path, GL_FRAGMENT_SHADER);
	free(path);
	if (err != NO_ERROR)
		error_put_from_struct(&context->frag_shader.error);
	if (program_prepare(&context->gpu_program, &context->vert_shader,
				&context->frag_shader) != NO_ERROR)
		error_put_from_struct(&context->gpu_program.error);
	return (err);
}
