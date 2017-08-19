/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 19:25:50 by jleu              #+#    #+#             */
/*   Updated: 2017/02/28 19:27:05 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# define RAD(deg)		((deg) * (float)M_PI / 180.0f)
# define DEG(rad)		((rad) * 180.0f / (float)M_PI)

# include "libftxml.h"

typedef struct	s_ivec2
{
	int		x;
	int		y;
}				t_ivec2;

typedef struct	s_vec2
{
	float	x;
	float	y;
}				t_vec2;

typedef struct	s_vec3
{
	float	x;
	float	y;
	float	z;
}				t_vec3;

typedef struct	s_ray
{
	t_vec3	pos;
	t_vec3	dir;
}				t_ray;

typedef struct	s_vec4
{
	float	x;
	float	y;
	float	z;
	float	w;
}				t_vec4;

typedef struct s_camera	t_camera;

t_ivec2			ivec2(const int x, const int y);
t_vec2			vec2(const float x, const float y);
t_vec3			vec3(const float x, const float y, const float z);
t_vec3			*vec3_set(t_vec3 *const vec3, const float x,
				const float y, const float z);
/*
**	setp TAKES RADIANS
**	PHI = VERTICAL AXIS, THETA = HORIZONTAL AXIS
*/

t_vec3			*vec3_setp(t_vec3 *const v, const float phi, const float theta);
t_vec3			*vec3_normalize(t_vec3 *const v);
t_vec3			*vec3_scale(t_vec3 *const v, const float factor);
t_vec3			*vec3_clamp(t_vec3 *v, float min, float max);
t_vec3			vec3_max(t_vec3 const *a, t_vec3 const *b);
t_vec3			vec3_min(t_vec3 const *a, t_vec3 const *b);
void			vec3_add(t_vec3 *a, t_vec3 const *b);
void			vec3_mul(t_vec3 *a, t_vec3 const *b);
int				vec3_parse(t_vec3 *vec, t_xml_element const *elem);
int				vec3_parse_color(t_vec3 *vec, t_xml_element const *elem);

t_ray			ray_from_coords(const t_ivec2 coords, t_camera *const camera,
				const float ratio);

#endif
