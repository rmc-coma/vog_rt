/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 15:21:02 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/02/28 18:32:34 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTEXT_H
# define CONTEXT_H

# include <SDL2/SDL.h>

# include "gl_include.h"
# include "vector.h"
# include "shader.h"
# include "program.h"
# include "hardware.h"
# include "libftxml.h"
# include "xml_parsing.h"
# include "scene.h"

typedef	struct	s_context
{
	t_scene			scene;
	unsigned char	render;
	SDL_GLContext	gl_ptr;
	GLuint			gl_framebuffer;
	GLint			width;
	GLint			height;
	t_ivec2			pos;
	GLfloat			ratio;
	t_hardware		hardware;
	t_shader		vert_shader;
	t_shader		frag_shader;
	t_program		gpu_program;
	GLuint			vbo_id;
	GLuint			vao_id;
	char			*exec_dir;
	GLuint			ratio_location;
	GLuint			width_location;
	GLuint			height_location;
}				t_context;

int				context_create(t_context *const context,
					char const *exec_filename);
t_context		*context_init(t_context *const context);
t_context		*context_vbo_init(t_context *const context);
t_context		*context_vao_init(t_context *const context);
int				context_program_init(t_context *const context,
					char const *exec_filename);
void			context_set_exec_dir(t_context *const context,
					char const *exec_filename);
t_context		*context_draw(t_context *const context,
					struct s_scene *const scene);
int				context_parse(t_context *context, t_xml_element const *elem);
t_context		*context_render_switch(t_context *const context);
char			context_is_on(t_context *const context, t_ivec2 *const pos);

#endif
