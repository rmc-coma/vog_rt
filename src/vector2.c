/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 01:49:19 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/01/22 03:59:53 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_ivec2		ivec2(const int x, const int y)
{
	t_ivec2	vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}

t_vec2		vec2(const float x, const float y)
{
	t_vec2	vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}
