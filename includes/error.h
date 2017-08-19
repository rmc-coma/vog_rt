/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 15:06:57 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/02/28 18:39:07 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "gl_include.h"

# define NO_ERROR							1
# define ERROR								-1
# define ERR_INVALID_PARAM					0

# define ERR_PARABOLOID						(ERROR - (1 << 33))
# define ERR_PARABOLOID_PARAM					(ERR_PARABOLOID - 1)

# define ERR_ELLIPSOID						(ERROR - (1 << 32))
# define ERR_ELLIPSOID_PARAM					(ERR_ELLIPSOID - 1)

# define ERR_PHONG							(ERROR - (1 << 31))
# define ERR_PHONG_PARAM					(ERR_PHONG - 1)

# define ERR_MATERIAL						(ERROR - (1 << 30))
# define ERR_MATERIAL_PARAM					(ERR_MATERIAL - 1)

# define ERR_SPHERE							(ERROR - (1 << 29))
# define ERR_SPHERE_PARAM					(ERR_SPHERE - 1)

# define ERR_PLANE							(ERROR - (1 << 28))
# define ERR_PLANE_PARAM					(ERR_PLANE - 1)

# define ERR_CONE							(ERROR - (1 << 27))
# define ERR_CONE_PARAM						(ERR_CONE - 1)

# define ERR_CYLINDER						(ERROR - (1 << 26))
# define ERR_CYLINDER_PARAM					(ERR_CYLINDER - 1)

# define ERR_GEOMETRY						(ERROR - (1 << 25))
# define ERR_GEOMETRY_PARAM					(ERR_GEOMETRY - 1)

# define ERR_MESH							(ERROR - (1 << 24))
# define ERR_MESH_PARAM						(ERR_MESH - 1)

# define ERR_POINT							(ERROR - (1 << 23))
# define ERR_POINT_PARAM					(ERR_POINT - 1)

# define ERR_SPOT							(ERROR - (1 << 22))
# define ERR_SPOT_PARAM						(ERR_SPOT - 1)

# define ERR_LIGHT							(ERROR - (1 << 21))
# define ERR_LIGHT_PARAM					(ERR_LIGHT - 1)

# define ERR_CSG							(ERROR - (1 << 20))
# define ERR_CSG_PARAM						(ERR_CSG - 1)

# define ERR_TRANSFORM						(ERROR - (1 << 19))
# define ERR_TRANSFORM_PARAM				(ERR_TRANSFORM - 1)

# define ERR_OBJECT							(ERROR - (1 << 18))
# define ERR_OBJECT_PARAM					(ERR_OBJECT - 1)
# define ERR_OBJECT_TRANSFORM_INIT			(ERR_OBJECT - 2)

# define ERR_RELATION						(ERROR - (1 << 17))
# define ERR_RELATION_PARAM					(ERR_RELATION - 1)

# define ERR_BOARD							(ERROR - (1 << 16))
# define ERR_BOARD_PARAM					(ERR_BOARD - 1)
# define ERR_BOARD_LSTAPPE					(ERR_BOARD - 2)
# define ERR_BOARD_LSTAPPD					(ERR_BOARD - 3)
# define ERR_BOARD_LSTAPPB					(ERR_BOARD - 4)
# define ERR_BOARD_LSTBINDE_EBOARD			(ERR_BOARD - 5)
# define ERR_BOARD_LSTBINDE_BOARD			(ERR_BOARD - 6)
# define ERR_BOARD_LSTBINDB_BBOARD			(ERR_BOARD - 7)
# define ERR_BOARD_LSTBINDB_BOARD			(ERR_BOARD - 8)
# define ERR_BOARD_LSTBINDD_DBOARD			(ERR_BOARD - 9)
# define ERR_BOARD_LSTBINDD_BOARD			(ERR_BOARD - 10)

# define ERR_DBOARD							(ERROR - (1 << 15))
# define ERR_DBOARD_PARAM					(ERR_DBOARD - 1)
# define ERR_DBOARD_LSTAPPE					(ERR_DBOARD - 2)
# define ERR_DBOARD_LSTAPPD					(ERR_DBOARD - 3)
# define ERR_DBOARD_LSTAPPB					(ERR_DBOARD - 4)
# define ERR_DBOARD_LSTBINDB_BOARD			(ERR_DBOARD - 5)
# define ERR_DBOARD_LSTBINDB_DBOARD			(ERR_DBOARD - 6)
# define ERR_DBOARD_LSTBINDE_EBOARD			(ERR_DBOARD - 7)
# define ERR_DBOARD_LSTBINDE_DBOARD			(ERR_DBOARD - 8)
# define ERR_DBOARD_LSTBINDD_DDBOARD		(ERR_DBOARD - 9)
# define ERR_DBOARD_LSTBINDD_DBOARD			(ERR_DBOARD - 10)

# define ERR_EBOARD							(ERROR - (1 << 14))
# define ERR_EBOARD_PARAM					(ERR_EBOARD - 1)

# define ERR_SDL							(ERROR - (1 << 13))
# define ERR_SDL_PARAM						(ERR_SDL - 1)
# define ERR_SDL_INIT						(ERR_SDL - 2)
# define ERR_SDL_WINDOW_CREATION			(ERR_SDL - 3)
# define ERR_SDL_CONTEXT_PARAM				(ERR_SDL - 4)
# define ERR_SDL_CONTEXT_CREATION			(ERR_SDL - 5)

# define ERR_SCENE							(ERROR - (1 << 12))
# define ERR_SCENE_PARAM					(ERR_SCENE - 1)
# define ERR_SCENE_INIT						(ERR_SCENE - 2)
# define ERR_SCENE_OBJECTS_BUFFER_EMPTY		(ERR_SCENE - 3)
# define ERR_SCENE_OBJECTS_ARRAY_EMPTY		(ERR_SCENE - 4)
# define ERR_SCENE_EMPTY_MATERIAL			(ERR_SCENE - 5)
# define ERR_SCENE_MATERIAL_ADDING			(ERR_SCENE - 6)
# define ERR_SCENE_EMPTY_GEOMETRY			(ERR_SCENE - 7)
# define ERR_SCENE_GEOMETRY_ADDING			(ERR_SCENE - 8)
# define ERR_SCENE_EMPTY_MESH				(ERR_SCENE - 9)
# define ERR_SCENE_MESH_ADDING				(ERR_SCENE - 10)
# define ERR_SCENE_EMPTY_LIGHT				(ERR_SCENE - 11)
# define ERR_SCENE_LIGHT_ADDING				(ERR_SCENE - 12)
# define ERR_SCENE_EMPTY_CSG				(ERR_SCENE - 13)
# define ERR_SCENE_CSG_ADDING				(ERR_SCENE - 14)
# define ERR_SCENE_EMPTY_OBJECT				(ERR_SCENE - 15)
# define ERR_SCENE_OBJECT_ADDING			(ERR_SCENE - 16)
# define ERR_SCENE_BIND_PARAM				(ERR_SCENE - 17)
# define ERR_SCENE_TRS2OBJ_BINDING			(ERR_SCENE - 18)
# define ERR_SCENE_TRS2OBJ_BINDING_OBJ		(ERR_SCENE - 19)
# define ERR_SCENE_TRS2OBJ_BINDING_TRS		(ERR_SCENE - 20)
# define ERR_SCENE_TRS2OBJ_BOUND_ALRDY		(ERR_SCENE - 21)
# define ERR_SCENE_MAT2MSH_BINDING			(ERR_SCENE - 22)
# define ERR_SCENE_MAT2MSH_BINDING_MSH		(ERR_SCENE - 23)
# define ERR_SCENE_MAT2MSH_BINDING_MAT		(ERR_SCENE - 24)
# define ERR_SCENE_MAT2MSH_BOUND_ALRDY		(ERR_SCENE - 25)
# define ERR_SCENE_GEO2MSH_BINDING			(ERR_SCENE - 26)
# define ERR_SCENE_GEO2MSH_BINDING_MSH		(ERR_SCENE - 27)
# define ERR_SCENE_GEO2MSH_BINDING_GEO		(ERR_SCENE - 28)
# define ERR_SCENE_GEO2MSH_BOUND_ALRDY		(ERR_SCENE - 29)
# define ERR_SCENE_LIT2OBJ_BINDING			(ERR_SCENE - 30)
# define ERR_SCENE_LIT2OBJ_BINDING_OBJ		(ERR_SCENE - 31)
# define ERR_SCENE_LIT2OBJ_BINDING_LIT		(ERR_SCENE - 32)
# define ERR_SCENE_LIT2OBJ_BOUND_ALRDY		(ERR_SCENE - 33)
# define ERR_SCENE_LIT2OBJ_OBJ_NOT_LIGHT	(ERR_SCENE - 34)
# define ERR_SCENE_CSG2OBJ_BINDING			(ERR_SCENE - 35)
# define ERR_SCENE_CSG2OBJ_BINDING_OBJ		(ERR_SCENE - 36)
# define ERR_SCENE_CSG2OBJ_BINDING_CSG		(ERR_SCENE - 37)
# define ERR_SCENE_CSG2OBJ_BOUND_ALRDY		(ERR_SCENE - 38)
# define ERR_SCENE_CSG2OBJ_OBJ_NOT_CSG		(ERR_SCENE - 39)
# define ERR_SCENE_MSH2OBJ_BINDING			(ERR_SCENE - 40)
# define ERR_SCENE_MSH2OBJ_BINDING_OBJ		(ERR_SCENE - 41)
# define ERR_SCENE_MSH2OBJ_BINDING_MSH		(ERR_SCENE - 42)
# define ERR_SCENE_MSH2OBJ_BOUND_ALRDY		(ERR_SCENE - 43)
# define ERR_SCENE_MSH2OBJ_OBJ_NOT_MESH		(ERR_SCENE - 44)
# define ERR_SCENE_OBJ2CSG_BINDING			(ERR_SCENE - 45)
# define ERR_SCENE_OBJ2CSG_BINDING_CSG		(ERR_SCENE - 46)
# define ERR_SCENE_OBJ2CSG_BINDING_OBJ		(ERR_SCENE - 47)
# define ERR_SCENE_OBJ2CSG_BOUND_ALRDY		(ERR_SCENE - 48)
# define ERR_SCENE_OBJ2CSG_OBJ_NOT_MESH		(ERR_SCENE - 49)

# define ERR_CAMERA							(ERROR - (1 << 11))
# define ERR_CAMERA_PARAM					(ERR_CAMERA - 1)
# define ERR_CAMERA_INIT					(ERR_CAMERA - 2)

# define ERR_VERTEX_SHADER					(ERROR - (1 << 10))
# define ERR_VERTEX_SHADER_PARAM			(ERR_VERTEX_SHADER - 1)
# define ERR_VERTEX_SHADER_INVALID_PATH		(ERR_VERTEX_SHADER - 2)
# define ERR_VERTEX_SHADER_GL_CREATION		(ERR_VERTEX_SHADER - 3)
# define ERR_VERTEX_SHADER_INVALID_FILE		(ERR_VERTEX_SHADER - 4)

# define ERR_FRAGMENT_SHADER				(ERROR - (1 << 9))
# define ERR_FRAGMENT_SHADER_PARAM			(ERR_FRAGMENT_SHADER - 1)
# define ERR_FRAGMENT_SHADER_INVALID_PATH	(ERR_FRAGMENT_SHADER - 2)
# define ERR_FRAGMENT_SHADER_GL_CREATION	(ERR_FRAGMENT_SHADER - 3)
# define ERR_FRAGMENT_SHADER_INVALID_FILE	(ERR_FRAGMENT_SHADER - 4)

# define ERR_PROGRAM						(ERROR - (1 << 8))
# define ERR_PROGRAM_PARAM					(ERR_PROGRAM - 1)
# define ERR_PROGRAM_INVALID_VERTEX			(ERR_PROGRAM - 2)
# define ERR_PROGRAM_INVALID_FRAGMENT		(ERR_PROGRAM - 3)
# define ERR_PROGRAM_GL_CREATION			(ERR_PROGRAM - 4)

# define ERR_BUFFER							(ERROR - (1 << 7))
# define ERR_BUFFER_PARAM					(ERR_BUFFER - 1)
# define ERR_BUFFER_ALREADY_SET				(ERR_BUFFER - 2)
# define ERR_BUFFER_DELETE					(ERR_BUFFER - 3)

# define ERR_BUFFER_LIST					(ERROR - (1 << 6))
# define ERR_BUFFER_LIST_APP_PARAM			(ERR_BUFFER_LIST - 1)
# define ERR_BUFFER_LIST_APP_INVALID		(ERR_BUFFER_LIST - 2)
# define ERR_BUFFER_LIST_DEL_PARAM			(ERR_BUFFER_LIST - 3)
# define ERR_BUFFER_LIST_DELONE_PARAM		(ERR_BUFFER_LIST - 4)

# define ERR_LOOP							(ERROR - (1 << 5))
# define ERR_LOOP_PARAM						(ERR_LOOP - 1)

# define ERR_SHADER							(ERROR - (1 << 4))

struct s_program;
struct s_shader;

typedef struct	s_error
{
	char	*wording;
	int		code;
}				t_error;

int				error_check_program(struct s_program *const program,
									const GLint gl_flag);
int				error_check_shader(struct s_shader *const shader,
									const GLint gl_flag);
int				error_set(t_error *const error, const int code,
									const char *const wording);
void			error_put_from_struct(t_error *const error);
void			error_put_from_code(const int code);

#endif
