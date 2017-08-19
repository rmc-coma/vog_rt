/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:29:21 by calemany          #+#    #+#             */
/*   Updated: 2014/11/05 17:53:07 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n != 0)
	{
		if (*((char*)s1) != *((char*)s2))
			return (*((unsigned char*)s1) - *((unsigned char*)s2));
		++s1;
		++s2;
		--n;
	}
	return (0);
}
