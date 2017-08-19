/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwordend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 12:30:57 by calemany          #+#    #+#             */
/*   Updated: 2015/02/23 09:29:38 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"
#include "ft_string.h"

char		*ft_strwordend(char const *s)
{
	char const		*it;

	while (*s && !ft_isspace(*s))
	{
		if (ft_isquote(*s))
		{
			it = ft_strchr(s + 1, *s);
			if (it)
				s = it + 1;
			else
				s += ft_strlen(s);
		}
		else
			++s;
	}
	return ((char*)s);
}
