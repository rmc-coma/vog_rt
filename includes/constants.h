/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 04:27:55 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/02/28 18:27:52 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

# ifndef NULL
#  define NULL										(void *)0
# endif

# ifndef BUFFER_OFFSET
#  define BUFFER_OFFSET(offset)						((char *)NULL + (offset))
# endif

# define CONST_CONTEXT_RATIO_SHADER_VARNAME			"s_ratio"

# define CONST_GUI_FRAME_SHADER_VARNAME				"text"
# define CONST_GUI_FRAME_POS_SHADER_VARNAME			"text_pos"
# define CONST_GUI_FRAME_WIDTH_SHADER_VARNAME		"text_width"
# define CONST_GUI_FRAME_HEIGHT_SHADER_VARNAME		"text_height"
# define CONST_GUI_CONTEXT_WIDTH_SHADER_VARNAME		"c_width"
# define CONST_GUI_CONTEXT_HEIGHT_SHADER_VARNAME	"c_height"
# define CONST_GUI_FRAMETEXTURE_SHADER_VARNAME		"frametexture"
# define CONST_GUI_WINDOW_WIDTH_SHADER_VARNAME		"s_width"
# define CONST_GUI_WINDOW_HEIGHT_SHADER_VARNAME		"s_height"

# define CONST_N_ELEMENTS							12

# define CONST_OBJECT_MESH_SLOT						0
# define CONST_OBJECT_TRANSFORM_SLOT				1

# define CONST_MESH_GEOMETRY_SLOT					0
# define CONST_MESH_MATERIAL_SLOT					1

# define CONST_GEOMETRY_VALUE_SLOT					0

#endif
