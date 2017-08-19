/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 21:44:14 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/02/28 19:19:11 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROGRAM_H
# define PROGRAM_H

# include "shader.h"
# include "error.h"
# include "gl_include.h"

typedef struct	s_program
{
	GLuint		gl_id;
	t_error		error;
}				t_program;

int				program_init(t_program *const program);
int				program_prepare(t_program *const program,
					const t_shader *const vertex_shader,
					const t_shader *const fragment_shader);
int				program_destroy(t_program *const program);

#endif
