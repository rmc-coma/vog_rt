/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:24:45 by calemany          #+#    #+#             */
/*   Updated: 2014/11/05 19:30:25 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*map;
	size_t	n;
	size_t	i;

	n = ft_strlen(s);
	map = (char*)malloc((n + 1) * sizeof(char));
	if (map == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		map[i] = f(s[i]);
		++i;
	}
	map[i] = '\0';
	return (map);
}
