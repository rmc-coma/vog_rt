/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strhextoint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 16:38:30 by calemany          #+#    #+#             */
/*   Updated: 2015/03/20 10:25:07 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <limits.h>

int		ft_strhextoint(char const *s, int *n)
{
	long	i;

	i = 0;
	if (!ft_strncmp(s, "0x", 2))
		s += 2;
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
		if (i > INT_MAX)
			return (1);
		++s;
	}
	*n = i;
	return (0);
}
