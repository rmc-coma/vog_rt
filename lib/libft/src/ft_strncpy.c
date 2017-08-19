/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:16:54 by calemany          #+#    #+#             */
/*   Updated: 2014/11/03 19:52:51 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		if (src[i] == '\0')
		{
			while (i < n)
			{
				dst[i] = '\0';
				++i;
			}
			return (dst);
		}
		++i;
	}
	return (dst);
}
