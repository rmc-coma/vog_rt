/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:34:18 by calemany          #+#    #+#             */
/*   Updated: 2014/11/03 19:51:36 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char *s1_cp;

	s1_cp = s1;
	while (*s1 != '\0')
		++s1;
	while (n > 0 && *s2 != '\0')
	{
		*s1 = *s2;
		++s1;
		++s2;
		--n;
	}
	*s1 = '\0';
	return (s1_cp);
}
