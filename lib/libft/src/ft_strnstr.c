/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 21:37:57 by calemany          #+#    #+#             */
/*   Updated: 2014/11/08 18:08:24 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int			i;
	const char	*end;

	if (*s2 == '\0')
		return ((char*)s1);
	end = s1 + n;
	while (*s1 != '\0' && s1 < end)
	{
		i = 0;
		while (s1[i] == s2[i] && s1[i] != '\0' && s1 + i < end)
			++i;
		if (s2[i] == '\0')
			return ((char*)s1);
		++s1;
	}
	return (NULL);
}
