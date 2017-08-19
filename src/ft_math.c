/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 01:22:08 by jleu              #+#    #+#             */
/*   Updated: 2017/03/01 01:22:10 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

float	fclamp(float a, float min, float max)
{
	if (a < min)
		a = min;
	else if (a > max)
		a = max;
	return (a);
}

float	ft_fmin(float a, float b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

float	ft_fmax(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
