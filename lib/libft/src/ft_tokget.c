/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 11:10:24 by calemany          #+#    #+#             */
/*   Updated: 2015/02/18 11:10:28 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"
#include "ft_string.h"
#include <stdlib.h>

char	**ft_tokget(char const *s, char const **sep, char const **end)
{
	char const		**it_max;
	size_t			size;
	size_t			size_max;

	it_max = NULL;
	size_max = 0;
	while (*sep)
	{
		size = ft_strlen(*sep);
		if (size > size_max && !ft_strncmp(*sep, s, size))
		{
			size_max = size;
			it_max = sep;
		}
		++sep;
	}
	if (end)
		*end = s + size_max;
	return ((char**)it_max);
}
