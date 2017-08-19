/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:57:14 by calemany          #+#    #+#             */
/*   Updated: 2014/11/08 19:23:17 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	const char *pos;

	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			pos = s;
			while (*s != '\0')
			{
				if (*s == (char)c)
					pos = s;
				++s;
			}
			if (c == '\0')
				return ((char*)s);
			return ((char*)pos);
		}
		++s;
	}
	if (c == '\0')
		return ((char*)s);
	return (NULL);
}
