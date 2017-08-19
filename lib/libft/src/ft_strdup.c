/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:59:14 by calemany          #+#    #+#             */
/*   Updated: 2014/11/05 18:05:07 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

char	*ft_strdup(const char *s1)
{
	size_t	n;
	char	*cp;

	n = ft_strlen(s1) + 1;
	cp = malloc(n * sizeof(char));
	if (cp == NULL)
		return (NULL);
	return (ft_memcpy(cp, s1, n));
}
