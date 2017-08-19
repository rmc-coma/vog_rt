/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datamodel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 00:58:37 by jleu              #+#    #+#             */
/*   Updated: 2017/03/01 01:12:21 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "datamodel.h"
#include "ft_mem.h"
#include "shad_struct.h"

static void	data_offset(t_datamodel *datamodel)
{
	GLuint	i;

	datamodel->offsets = (GLintptr *)ft_memalloc(sizeof(GLintptr) *
						datamodel->n_offsets);
	i = 0;
	while (i < datamodel->n_offsets)
	{
		datamodel->offsets[i] = i > 0 ? datamodel->offsets[i - 1] : 0;
		if (datamodel->sizes[i + 1] > 4)
		{
			datamodel->offsets[i] += 4;
			while (datamodel->offsets[i] % 16 != 0)
				datamodel->offsets[i] += 4;
		}
		else
			datamodel->offsets[i] += datamodel->sizes[i];
		++i;
	}
	datamodel->total_size = datamodel->offsets[i - 1] + datamodel->sizes[i];
	while (datamodel->total_size % 16 != 0)
		datamodel->total_size += 4;
}

t_datamodel	*datamodel_init(t_datamodel *datamodel,
		t_shad_struct const *shad_struct)
{
	GLuint			i;
	GLuint			n_sizes;

	n_sizes = shad_struct->n_vars;
	datamodel->n_sizes = n_sizes;
	datamodel->sizes = (GLsizeiptr *)ft_memalloc(sizeof(GLsizeiptr) * n_sizes);
	i = 0;
	while (i < n_sizes)
	{
		datamodel->sizes[i] = shad_struct->varsize[i];
		++i;
	}
	datamodel->n_offsets = n_sizes - 1;
	if (datamodel->n_offsets == 0)
	{
		datamodel->offsets = (GLintptr *)0;
		datamodel->total_size = 16;
	}
	else
		data_offset(datamodel);
	return (datamodel);
}
