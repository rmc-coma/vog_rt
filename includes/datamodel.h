/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datamodel.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 18:31:52 by jleu              #+#    #+#             */
/*   Updated: 2017/02/28 18:31:59 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATAMODEL_H
# define DATAMODEL_H

# include "gl_include.h"
# include "shad_struct.h"

typedef struct	s_datamodel
{
	GLsizeiptr	total_size;
	GLuint		n_sizes;
	GLsizeiptr	*sizes;
	GLuint		n_offsets;
	GLintptr	*offsets;
}				t_datamodel;

t_datamodel		*datamodel_init(t_datamodel *datamodel,
		t_shad_struct const *shad_struct);

#endif
