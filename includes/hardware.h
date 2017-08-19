/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardware.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 16:23:08 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/12/29 01:58:40 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARDWARE_H
# define HARDWARE_H

# include "gl_include.h"

typedef struct	s_hardware
{
	GLint	uniform_buffers_num;
	GLint	uniform_buffer_size;
	GLint	uniform_buffer_align;
}				t_hardware;

int				hardware_init(t_hardware *const hw);

#endif
