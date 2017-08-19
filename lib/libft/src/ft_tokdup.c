/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 10:18:07 by calemany          #+#    #+#             */
/*   Updated: 2015/02/18 13:05:34 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"
#include "ft_string.h"

char		*ft_tokdup(char const *s, char const **sep, char const **end)
{
	char const	*it;
	char const	*it2;
	char		**tok;

	if ((tok = ft_tokget(s, sep, end)))
		return (ft_strdup(*tok));
	it = s;
	while (*it && !ft_tokget(it, sep, NULL))
	{
		if (ft_isquote(*it))
		{
			if ((it2 = ft_strchr(it + 1, *it)))
				it = it2 + (*it2 != '\0');
			else
				it += ft_strlen(it);
		}
		else
			++it;
	}
	if (end)
		*end = it;
	return (ft_strsub2(s, it));
}
