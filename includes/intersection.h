/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 06:00:20 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/01/22 06:03:18 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H

# ifndef FALSE
#  define FALSE	0
# endif
# ifndef TRUE
#  define TRUE !FALSE
# endif

# include "vector.h"

typedef unsigned char	t_bool;

typedef struct			s_inter
{
	t_bool		exists;
	t_vec3		point;
	s_ray		ray;
	float		dist_sq;
	t_object	*object;
}						t_inter;

#endif
