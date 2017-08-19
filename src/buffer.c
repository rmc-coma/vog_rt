/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 15:07:45 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/08 16:14:10 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"
#include "error.h"
#include <stdlib.h>

int			buffer_init(t_buffer *const buffer, const GLenum target,
						const GLenum usage)
{
	if (!buffer)
		return (ERR_BUFFER_PARAM);
	buffer->gl_id = 0;
	buffer->target = target;
	buffer->usage = usage;
	buffer->data = (GLvoid *)0;
	buffer->size = 0;
	buffer->offset = 0;
	return (NO_ERROR);
}

t_buffer	*buffer_new(const GLenum target, const GLenum usage)
{
	t_buffer	*new;

	if (!(new = (t_buffer *)malloc(sizeof(t_buffer))))
		return ((void *)0);
	buffer_init(new, target, usage);
	return (new);
}

int			buffer_set(t_buffer *const buffer, const GLsizeiptr size,
					const GLintptr offset, GLvoid *data)
{
	if (!buffer || !size)
		return (ERR_BUFFER_PARAM);
	if (buffer->gl_id != 0)
		return (ERR_BUFFER_ALREADY_SET);
	buffer->size = size;
	buffer->offset = offset;
	buffer->data = data;
	glGenBuffers(1, &buffer->gl_id);
	glBindBuffer(buffer->target, buffer->gl_id);
	glBufferData(buffer->target, size, 0, buffer->usage);
	glBufferSubData(buffer->target, offset, size, data);
	glBindBuffer(buffer->target, 0);
	return (NO_ERROR);
}

int			buffer_unset(t_buffer *const buffer)
{
	if (!buffer)
		return (ERR_BUFFER_PARAM);
	glDeleteBuffers(1, &buffer->gl_id);
	buffer->gl_id = 0;
	return (NO_ERROR);
}

int			buffer_delete(t_buffer *const buffer)
{
	if (!buffer)
		return (ERR_BUFFER_PARAM);
	if (!buffer->size)
		return (ERR_BUFFER_DELETE);
	if (buffer->gl_id)
		buffer_unset(buffer);
	buffer->size = 0;
	buffer->offset = 0;
	free(buffer->data);
	buffer->data = (GLvoid *)0;
	return (NO_ERROR);
}
