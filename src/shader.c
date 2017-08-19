/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 23:01:00 by jleu              #+#    #+#             */
/*   Updated: 2017/03/13 15:29:42 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shader.h"
#include "get_next_line.h"
#include "ft_str.h"
#include "ft_list.h"
#include "ft_mem.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "debug.h"

static int	set_shader_error(int cas, t_shader *const shader, GLuint gl_type)
{
	if (cas == 0)
	{
		if (gl_type == GL_VERTEX_SHADER)
			error_set(&shader->error, ERR_VERTEX_SHADER_INVALID_PATH,
					"Invalid vertex shader path");
		else
			error_set(&shader->error, ERR_FRAGMENT_SHADER_INVALID_PATH,
					"Invalid fragment shader path");
	}
	else if (cas == 1)
	{
		if (gl_type == GL_VERTEX_SHADER)
			error_set(&shader->error, ERR_VERTEX_SHADER_GL_CREATION,
					"Couldn't create vertex shader");
		else
			error_set(&shader->error, ERR_FRAGMENT_SHADER_GL_CREATION,
					"Couldn't create fragment shader");
	}
	return (ERROR);
}

static void	shader_read(int *n_line, int fd, char **line, t_list **lines)
{
	*line = NULL;
	*lines = NULL;
	*n_line = 0;
	while (get_next_line(fd, line) > 0)
	{
		if (ft_strlen(*line) > 0)
		{
			ft_lstapp(lines, ft_lstnew((void *)*line, ft_strlen(*line)));
			++*n_line;
		}
		free(*line);
	}
	close(fd);
}

static void	shader_lines_treatment(t_shader *const shader, t_list **lines,
									int n_line)
{
	t_list	*next_line;
	int		i;

	i = 0;
	shader->source = (GLchar **)malloc(sizeof(GLchar *) * (n_line + 1));
	while (*lines != NULL)
	{
		shader->source[i] = (GLchar *)ft_memdup((char *)((*lines)->content),
							(*lines)->content_size + 2);
		shader->source[i][(*lines)->content_size] = '\n';
		shader->source[i++][(*lines)->content_size + 1] = 0;
		next_line = (*lines)->next;
		free((*lines)->content);
		free(*lines);
		*lines = next_line;
	}
}

int			shader_prepare(t_shader *const shader, const char *const path,
					GLuint gl_type)
{
	int		fd;
	int		n_line;
	GLuint	shader_id;
	char	*line;
	t_list	*lines;

	if (!shader || (gl_type != GL_VERTEX_SHADER
				&& gl_type != GL_FRAGMENT_SHADER))
		return (ERR_INVALID_PARAM);
	if ((fd = open(path, O_RDONLY)) < 1)
		return (set_shader_error(0, shader, gl_type));
	if (!(shader_id = glCreateShader(gl_type)))
		return (set_shader_error(1, shader, gl_type));
	shader_read(&n_line, fd, &line, &lines);
	shader_lines_treatment(shader, &lines, n_line);
	shader->source[n_line] = NULL;
	glShaderSource(shader_id, n_line,
			(const GLchar *const *)shader->source, NULL);
	glCompileShader(shader_id);
	shader->path = ft_strdup(path);
	shader->gl_type = gl_type;
	shader->gl_id = shader_id;
	return (error_check_shader(shader, GL_COMPILE_STATUS));
}

int			shader_delete(t_shader *const shader)
{
	int		i;

	if (shader)
	{
		i = 0;
		if (shader->source)
		{
			while (shader->source[i])
				free(shader->source[i++]);
			free(shader->source);
		}
		if (shader->path)
			free(shader->path);
		if (glIsShader(shader->gl_id))
			glDeleteShader(shader->gl_id);
		else
			return (0);
		return (1);
	}
	return (0);
}
