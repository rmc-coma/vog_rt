/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 21:14:44 by calemany          #+#    #+#             */
/*   Updated: 2014/11/06 14:48:30 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t i;

	if (*s2 == '\0')
		return ((char*)s1);
	while (*s1 != '\0')
	{
		i = 0;
		while (s1[i] == s2[i])
		{
			++i;
			if (s2[i] == '\0')
				return ((char*)s1);
			if (s1[i] == '\0')
				return (NULL);
		}
		++s1;
	}
	return (NULL);
}
