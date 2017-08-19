/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:26:18 by calemany          #+#    #+#             */
/*   Updated: 2014/11/05 16:49:07 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	if (src > dst)
	{
		i = 0;
		while (i < len)
		{
			((char*)dst)[i] = ((char*)src)[i];
			++i;
		}
	}
	else if (dst > src)
	{
		i = len;
		while (i > 0)
		{
			--i;
			((char*)dst)[i] = ((char*)src)[i];
		}
	}
	return (dst);
}
