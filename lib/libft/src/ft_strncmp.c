/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 21:49:32 by calemany          #+#    #+#             */
/*   Updated: 2014/11/05 17:13:04 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 == *s2 && *s1 != '\0')
	{
		--n;
		if (n == 0)
			return (0);
		++s1;
		++s2;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
