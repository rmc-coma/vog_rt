/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 14:43:29 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/13 15:35:23 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"
#include "ft_str.h"
#include "debug.h"

int			program_init(t_program *const program)
{
	if (!program)
		return (ERR_INVALID_PARAM);
	program->gl_id = 0;
	program->error.code = 0;
	program->error.wording = (void *)0;
	return (NO_ERROR);
}

static void	program_prepare2(t_program *const program,
					const t_shader *const vertex_shader,
					const t_shader *const fragment_shader)
{
	glAttachShader(program->gl_id, vertex_shader->gl_id);
	glAttachShader(program->gl_id, fragment_shader->gl_id);
	glBindAttribLocation(program->gl_id, 0, "in_scoords");
	glLinkProgram(program->gl_id);
}

int			program_prepare(t_program *const program,
					const t_shader *const vertex_shader,
					const t_shader *const fragment_shader)
{
	if (!program)
		return (ERR_INVALID_PARAM);
	if (!glIsShader(vertex_shader->gl_id))
	{
		program->error.code = ERR_PROGRAM_INVALID_VERTEX;
		program->error.wording = ft_strdup("Given vertex shader is invalid");
		return (ERROR);
	}
	if (!glIsShader(fragment_shader->gl_id))
	{
		program->error.code = ERR_PROGRAM_INVALID_FRAGMENT;
		program->error.wording = ft_strdup("Given fragment shader is invalid");
		return (ERROR);
	}
	program->gl_id = glCreateProgram();
	if (!glIsProgram(program->gl_id))
	{
		program->error.code = ERR_PROGRAM_GL_CREATION;
		program->error.wording = ft_strdup("Failed to create program");
		return (ERROR);
	}
	program_prepare2(program, vertex_shader, fragment_shader);
	return (error_check_program(program, GL_LINK_STATUS));
}

int			program_destroy(t_program *const program)
{
	if (program && glIsProgram(program->gl_id))
	{
		glDeleteProgram(program->gl_id);
		return (1);
	}
	return (0);
}
