/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:25:14 by calemany          #+#    #+#             */
/*   Updated: 2014/11/03 19:49:08 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t i;

	i = 0;
	while (i != n)
	{
		((char*)dst)[i] = ((char*)src)[i];
		++i;
	}
	return (dst);
}
