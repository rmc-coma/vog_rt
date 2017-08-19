/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 21:13:12 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/02/28 19:20:44 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADER_H
# define SHADER_H

# include "error.h"
# include "gl_include.h"

typedef struct	s_shader
{
	GLuint		gl_type;
	GLuint		gl_id;
	GLchar		**source;
	char		*path;
	t_error		error;
}				t_shader;

int				shader_prepare(t_shader *const shader, const char *const path,
				GLuint shader_type);
int				shader_delete(t_shader *const shader);

#endif
