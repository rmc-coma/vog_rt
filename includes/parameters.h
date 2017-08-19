/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 14:44:11 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/02/28 19:18:28 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMETERS_H
# define PARAMETERS_H

# include <SDL2/SDL.h>
# include "libftxml.h"

# ifndef BUFFER_OFFSET
#  define BUFFER_OFFSET(offset) ((char *)0 + (offset))

# endif

# ifndef FALSE
#  define FALSE							0
# endif
# ifndef TRUE
#  define TRUE							!FALSE
# endif

# define VSYNC_ACTIVE					0

# define DEBUG_ACTIVE					1

# define WINDOW_WIDTH					1680
# define WINDOW_HEIGHT					720
# define WINDOW_TITLE					"RT"
# define WINDOW_X_POS					(SDL_WINDOWPOS_CENTERED)
# define WINDOW_Y_POS					(SDL_WINDOWPOS_CENTERED)
# define WINDOW_FLAGS					(SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL)

# define CONTEXT_WIDTH					1280
# define CONTEXT_HEIGHT					720
# define CONTEXT_X_POS					((WINDOW_WIDTH - CONTEXT_WIDTH) / 2)
# define CONTEXT_Y_POS					((WINDOW_HEIGHT - CONTEXT_HEIGHT) / 2)

# define GUI_FRAME_WIDTH				(WINDOW_WIDTH)
# define GUI_FRAME_HEIGHT				(WINDOW_HEIGHT)
# define GUI_FRAME_X_POS				0
# define GUI_FRAME_Y_POS				0

# define CAMERA_DEFAULT_NEAR			1.0f
# define CAMERA_DEFAULT_FOV				90.0f
# define CAMERA_DEFAULT_PHI				0.0f
# define CAMERA_DEFAULT_THETA			0.0f

# define MOVE_SPEED				10.0f
# define ROTATE_SPEED			30.0f

/*
**	MOVE_SPEED USES UNITS PER SECONDS
**	ROTATE_SPEED USES DEGREES PER SECONDS
*/

# define SHADER_CONTEXT_VERTEX_PATH		"shaders/context.vert"
# define SHADER_CONTEXT_FRAGMENT_PATH	"shaders/context.frag"
# define SHADER_GUI_VERTEX_PATH			"shaders/gui.vert"
# define SHADER_GUI_FRAGMENT_PATH		"shaders/gui.frag"

# define GUI_FONT_PATH					"font/ugly.bmp"

struct s_environment;

typedef unsigned char	t_bool;

int						parameters_parse(struct s_environment *env,
						t_xml_element const *elem);

#endif
