/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strhextouns.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 17:01:31 by calemany          #+#    #+#             */
/*   Updated: 2015/03/20 10:24:38 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <limits.h>

int		ft_strhextouns(char const *s, unsigned int *n)
{
	unsigned long	i;

	if (!ft_strncmp(s, "0x", 2))
		s += 2;
	i = 0;
	while (*s)
	{
		if (ft_isdigit(*s))
			i = 16 * i + *s - '0';
		else if ('a' <= *s && *s <= 'z')
			i = 16 * i + *s + 10 - 'a';
		else if ('A' <= *s && *s <= 'Z')
			i = 16 * i + *s + 10 - 'A';
		else
			return (1);
		if (i > UINT_MAX)
			return (1);
		++s;
	}
	*n = i;
	return (0);
}
