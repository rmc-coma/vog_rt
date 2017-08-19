/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 14:14:44 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/13 18:35:30 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "get_next_line.h"
#include "error.h"
#include "loop.h"
#include "parameters.h"
#include "vector.h"
#include "debug.h"
#include "create_scene.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "libft.h"
#include "libftxml.h"

static int	read_file(char const *filename, char **result)
{
	char	*file;
	char	*line;
	int		fd;
	int		err;

	fd = open(filename, O_RDONLY);
	file = 0;
	line = 0;
	if (!(err = (fd < 1)))
		while (get_next_line(fd, &line) > 0)
		{
			if (file)
			{
				ft_strappend(&file, "\n");
				ft_strappend(&file, line);
				free(line);
			}
			else
				file = line;
			line = 0;
		}
	close(fd);
	if (!err)
		*result = file;
	return (err);
}

static int	open_scene(t_scene *scene, char const *filename)
{
	int				err;
	char			*file;
	t_xml_element	xml;
	t_xml_error		xml_err;

	err = read_file(filename, &file);
	if (!err)
	{
		xml_element_init(&xml);
		xml_err = xml_parse(file, &xml);
		err = (xml_err != XML_SUCCESS);
		if (!err)
		{
			err = scene_parse(scene, &xml);
			if (err)
				ft_putstr_fd("scene parsing failed\n", 2);
			xml_element_free(&xml);
		}
		else
			xml_error_print(xml_err);
		free(file);
	}
	return (err);
}

static int	open_parameters(t_environment *env, char const *filename)
{
	int				err;
	char			*file;
	t_xml_element	xml;
	t_xml_error		xml_err;

	err = read_file(filename, &file);
	if (!err)
	{
		xml_element_init(&xml);
		xml_err = xml_parse(file, &xml);
		err = (xml_err != XML_SUCCESS);
		if (!err)
		{
			err = parameters_parse(env, &xml);
			if (err)
				ft_putstr_fd("parameters parsing failed\n", 2);
			xml_element_free(&xml);
		}
		else
			xml_error_print(xml_err);
		free(file);
	}
	return (err);
}

static void	close_all(t_environment *env)
{
	glDeleteProgram(env->window.context.gpu_program.gl_id);
	glDeleteShader(env->window.context.vert_shader.gl_id);
	glDeleteShader(env->window.context.frag_shader.gl_id);
	glDeleteProgram(env->window.gui.gpu_program.gl_id);
	glDeleteShader(env->window.gui.vert_shader.gl_id);
	glDeleteShader(env->window.gui.frag_shader.gl_id);
	glDeleteBuffers(1, &env->window.context.vbo_id);
	glDeleteVertexArrays(1, &env->window.context.vao_id);
	glDeleteBuffers(1, &env->window.gui.vbo_id);
	glDeleteVertexArrays(1, &env->window.gui.vao_id);
	SDL_GL_DeleteContext(env->window.context.gl_ptr);
	SDL_DestroyWindow(env->window.sdl_ptr);
	SDL_Quit();
}

int			main(int ac, char *av[])
{
	t_environment	env;

	if (ac != 3)
		return (-1);
	if (open_parameters(&env, av[1]))
		return (-2);
	window_create(&env.window);
	hardware_init(&env.window.context.hardware);
	if (context_create(&env.window.context, av[0]))
		return (-5);
	scene_init(&env.window.context.scene, &env.window.context);
	if (gui_create(&env.window.gui, &env.window.context, av[0]))
		return (-4);
	if (open_scene(&env.window.context.scene, av[2]))
		return (-6);
	ft_bzero((void *)&env.window.gui.stats, sizeof(t_stats));
	env.window.context.scene.current_obj =
		env.window.context.scene.cameras.first_node;
	loop_start(&env.window.context, &env.window.gui,
			&env.window.context.scene, &env.input);
	close_all(&env);
	return (0);
}
