/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:35:13 by calemany          #+#    #+#             */
/*   Updated: 2014/11/05 19:38:32 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*map;
	size_t			n;
	unsigned int	i;

	n = ft_strlen(s);
	map = (char*)malloc((n + 1) * sizeof(char));
	if (map == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		map[i] = f(i, s[i]);
		++i;
	}
	map[i] = '\0';
	return (map);
}
