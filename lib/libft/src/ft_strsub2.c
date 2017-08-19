/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 13:43:45 by calemany          #+#    #+#             */
/*   Updated: 2015/03/04 10:01:07 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

char	*ft_strsub2(char const *begin, char const *end)
{
	size_t		size;
	char		*cp;
	char		*it;

	if (end < begin)
		return (NULL);
	size = end - begin;
	cp = (char*)malloc((size + 1) * sizeof(char));
	if (cp)
	{
		it = cp;
		while (begin != end)
		{
			*it = *begin;
			++begin;
			++it;
		}
		*it = '\0';
	}
	return (cp);
}
