/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:57:54 by calemany          #+#    #+#             */
/*   Updated: 2014/11/14 17:54:08 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t add_max;
	size_t len;

	i = 0;
	while (dst[i] != '\0' && i < size)
		++i;
	len = i + ft_strlen(src);
	add_max = size - i - 1;
	if (i != size)
	{
		dst += i;
		i = 0;
		while (src[i] != '\0' && i < add_max)
		{
			dst[i] = src[i];
			++i;
		}
		dst[i] = '\0';
	}
	return (len);
}
