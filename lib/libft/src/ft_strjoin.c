/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 20:30:53 by calemany          #+#    #+#             */
/*   Updated: 2014/11/05 20:35:19 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			n;
	char			*join;

	n = ft_strlen(s1);
	join = (char*)malloc((n + 1 + ft_strlen(s2)) * sizeof(char));
	if (join != NULL)
	{
		ft_strcpy(join, s1);
		ft_strcpy(join + n, s2);
	}
	return (join);
}
