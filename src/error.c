/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 15:48:05 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/01 01:18:06 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "program.h"
#include "shader.h"
#include "ft_str.h"
#include <stdlib.h>
#include <unistd.h>

int		error_check_program(struct s_program *const program,
		const GLint gl_flag)
{
	GLint	wording_len;

	if (!program || !glIsProgram(program->gl_id))
		return ((program->error.code = ERR_INVALID_PARAM));
	glGetProgramiv(program->gl_id, gl_flag, &program->error.code);
	if (program->error.code != GL_TRUE)
	{
		program->error.code = NO_ERROR;
		wording_len = 0;
		glGetProgramiv(program->gl_id, GL_INFO_LOG_LENGTH, &wording_len);
		if (wording_len == 0)
			return ((program->error.code = ERR_INVALID_PARAM));
		program->error.wording = (char *)malloc(sizeof(char)
								* (wording_len + 1));
		program->error.wording[wording_len] = 0;
		glGetProgramInfoLog(program->gl_id, wording_len, &wording_len,
							program->error.wording);
		program->error.code = ERR_PROGRAM;
		return (ERR_PROGRAM);
	}
	program->error.code = NO_ERROR;
	return (NO_ERROR);
}

int		error_check_shader(struct s_shader *const shader, const GLint gl_flag)
{
	GLint	wording_len;

	if (!shader || !glIsShader(shader->gl_id))
		return ((shader->error.code = ERR_INVALID_PARAM));
	glGetShaderiv(shader->gl_id, gl_flag, &shader->error.code);
	if (shader->error.code != GL_TRUE)
	{
		shader->error.code = NO_ERROR;
		wording_len = 0;
		glGetShaderiv(shader->gl_id, GL_INFO_LOG_LENGTH, &wording_len);
		if (wording_len == 0)
			return ((shader->error.code = ERR_INVALID_PARAM));
		shader->error.wording = (char *)malloc(sizeof(char)
								* (wording_len + 1));
		shader->error.wording[wording_len] = 0;
		glGetShaderInfoLog(shader->gl_id, wording_len, &wording_len,
							shader->error.wording);
		shader->error.code = shader->gl_type == GL_VERTEX_SHADER ?
			ERR_VERTEX_SHADER : ERR_FRAGMENT_SHADER;
		return (ERR_SHADER);
	}
	shader->error.code = NO_ERROR;
	return (NO_ERROR);
}

int		error_set(t_error *const error, const int code,
					const char *const wording)
{
	if (!error)
		return (ERR_INVALID_PARAM);
	error->wording = ft_strdup(wording);
	error->code = code;
	return (NO_ERROR);
}

void	error_put_from_struct(t_error *const error)
{
	if (error && error->code != NO_ERROR && error->wording)
	{
		write(1, "\rclear\r", 7);
		write(1, error->wording, ft_strlen(error->wording));
		write(1, "\n", 1);
	}
}

void	error_put_from_code(const int code)
{
	char	*arr;

	arr = ft_itoa(code);
	write(1, "\rclear\r", 7);
	write(1, arr, ft_strlen(arr));
	write(1, "\n", 1);
	write(1, "\n", 1);
}
