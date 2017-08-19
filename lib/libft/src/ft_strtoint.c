/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 15:43:57 by calemany          #+#    #+#             */
/*   Updated: 2015/03/13 16:42:48 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <limits.h>

int				ft_strtoint(char const *s, int *n)
{
	long	i;
	int		sign;

	if (!ft_strncmp(s, "0x", 2))
		return (ft_strhextoint(s + 2, n));
	i = 0;
	sign = 1;
	if (*s == '+' || *s == '-')
		sign = 2 * (*s++ == '+') - 1;
	while (*s)
	{
		if (ft_isdigit(*s))
			i = 10 * i + (*s - '0') * sign;
		else
			return (1);
		if (INT_MAX < i || i < INT_MIN)
			return (1);
		++s;
	}
	*n = i;
	return (0);
}
