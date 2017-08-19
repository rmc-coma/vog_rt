/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubic.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 18:28:33 by jleu              #+#    #+#             */
/*   Updated: 2017/02/28 18:28:41 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBIC_H
# define CUBIC_H

# include "vector.h"
# include "xml_parsing.h"
# include "vector.h"

# include "libftxml.h"

/*
** Represents an equation of the form:
**   A3*x^3   + B3*y^3   + C3*z^3
** + A2B*x^2y + A2C*x^2z + ABC*xyz + AC2*xz^2 + B2C*y^2z + BC2*yz^2
** + A2*x^2   + B2*y^2   + C2*z^2  + AB*xy    + AC*xz    + BC*yz
** + A*x      + B*y      + C*z     + D
*/

typedef enum		e_cubic_coef
{
	CUBIC_A3,
	CUBIC_A2B,
	CUBIC_A2C,
	CUBIC_AB2,
	CUBIC_ABC,
	CUBIC_AC2,
	CUBIC_B3,
	CUBIC_B2C,
	CUBIC_BC2,
	CUBIC_C3,
	CUBIC_A2,
	CUBIC_AB,
	CUBIC_AC,
	CUBIC_B2,
	CUBIC_BC,
	CUBIC_C2,
	CUBIC_A,
	CUBIC_B,
	CUBIC_C,
	CUBIC_D,
	CUBIC_COEF_COUNT
}					t_coef_coef;

typedef struct		s_cubic
{
	t_vec3			size;
	float			radius;
	float			coef[CUBIC_COEF_COUNT];
}					t_cubic;

t_cubic				*cubic_new(void);
t_cubic				*cubic_init(t_cubic *const cubic);
int					cubic_parse(t_cubic *c, t_xml_element const *elem);
void				cubic_get_aabb(t_cubic const *c, t_vec3 *min, t_vec3 *max);

#endif
