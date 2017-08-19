/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:25:45 by calemany          #+#    #+#             */
/*   Updated: 2014/11/04 18:25:49 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n > 0)
	{
		*((unsigned char*)dst) = *((unsigned char*)src);
		if (*((unsigned char*)dst) == (unsigned char)c)
			return (dst + 1);
		++dst;
		++src;
		--n;
	}
	return (NULL);
}
