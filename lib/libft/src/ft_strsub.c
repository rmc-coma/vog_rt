/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 20:22:10 by calemany          #+#    #+#             */
/*   Updated: 2014/11/05 20:29:34 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	sub = (char*)malloc((len + 1) * sizeof(char));
	if (sub != NULL)
	{
		s += start;
		i = 0;
		while (i < len)
		{
			sub[i] = s[i];
			++i;
		}
		sub[i] = '\0';
	}
	return (sub);
}
