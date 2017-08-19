/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shad_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 03:07:47 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/02/28 19:19:51 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAD_STRUCT_H
# define SHAD_STRUCT_H

# define SHAD_STRUCT_VARSIZE_MAX 25

typedef enum		e_shad_struct_type
{
	SHAD_CAMERA,
	SHAD_OBJECT,
	SHAD_TRANSFORM,
	SHAD_LIGHT,
	SHAD_MESH,
	SHAD_GEOMETRY,
	SHAD_QUADRIC,
	SHAD_PLANE,
	SHAD_MATERIAL,
	SHAD_TORUS,
	SHAD_BOX,
	SHAD_MOBIUS,
	SHAD_CUBIC,
	SHAD_STRUCT_COUNT
}					t_shad_struct_type;

typedef struct		s_shad_struct
{
	int				base;
	char			*varname;
	char			*n_varname;
	int				has_type;
	int				n_children;
	int				n_vars;
	int				varsize[SHAD_STRUCT_VARSIZE_MAX];
}					t_shad_struct;

t_shad_struct const	*shad_struct_get(t_shad_struct_type type);

#endif
