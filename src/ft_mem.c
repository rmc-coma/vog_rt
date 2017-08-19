/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 01:27:52 by jleu              #+#    #+#             */
/*   Updated: 2017/03/01 01:28:30 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include <stdlib.h>

void	*ft_memdup(void *mem, size_t size)
{
	unsigned char	*dup;

	if (mem == NULL || size == 0)
		return (NULL);
	dup = (unsigned char *)malloc(sizeof(unsigned char) * size);
	if (dup == NULL)
		return (NULL);
	while (size--)
		dup[size] = ((unsigned char *)mem)[size];
	return ((void *)dup);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void			*tmpstr;

	tmpstr = malloc(sizeof(char) * len);
	ft_memcpy(tmpstr, src, len);
	ft_memcpy(dst, tmpstr, len);
	free(tmpstr);
	return (dst);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	while (n--)
		*(char *)(dst + n) = *(char *)(src + n);
	return (dst);
}

void	*ft_memalloc(size_t size)
{
	unsigned char	*mem;

	if (!(mem = (unsigned char *)malloc(sizeof(unsigned char) * size)))
		return ((void *)0);
	while (size--)
		mem[size] = 0;
	return ((void *)mem);
}
