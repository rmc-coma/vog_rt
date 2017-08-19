/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toksearch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 11:11:57 by calemany          #+#    #+#             */
/*   Updated: 2015/02/18 13:02:02 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"
#include "ft_string.h"

char	*ft_toksearch(char const *s, char const **sep)
{
	char const	*it;

	while (*s && !ft_tokget(s, sep, NULL))
	{
		if (ft_isquote(*s))
		{
			if ((it = ft_strchr(s + 1, *s)))
				s = it + (*it != '\0');
			else
				s += ft_strlen(s);
		}
		else
			++s;
	}
	return ((char*)s);
}
