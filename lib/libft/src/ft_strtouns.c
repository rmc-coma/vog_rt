/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtouns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 16:42:12 by calemany          #+#    #+#             */
/*   Updated: 2015/03/13 17:05:11 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <limits.h>

int		ft_strtouns(char const *s, unsigned int *n)
{
	unsigned long	i;

	if (!ft_strncmp(s, "0x", 2))
		return (ft_strhextouns(s, n));
	i = 0;
	while (*s)
	{
		if (ft_isdigit(*s))
			i = 10 * i + (*s - '0');
		else
			return (1);
		if (UINT_MAX < i)
			return (1);
		++s;
	}
	*n = i;
	return (0);
}
