/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardware.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 16:34:33 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/13 15:30:15 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hardware.h"
#include "debug.h"

int	hardware_init(t_hardware *const hw)
{
	if (!hw)
		return (0);
	glGetIntegerv(GL_MAX_UNIFORM_BUFFER_BINDINGS, &hw->uniform_buffers_num);
	glGetIntegerv(GL_MAX_UNIFORM_BLOCK_SIZE, &hw->uniform_buffer_size);
	glGetIntegerv(GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT,
				&hw->uniform_buffer_align);
	return (1);
}
