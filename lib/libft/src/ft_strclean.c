/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 15:27:51 by calemany          #+#    #+#             */
/*   Updated: 2016/06/05 13:01:10 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strclean(char const *s, int (*to_del)(char))
{
	int				size;
	char const		*it;
	char			*new;
	char			*it2;

	it = s;
	size = 0;
	while (*it)
		size += !to_del(*it++);
	if ((new = (char*)malloc((size + 1) * sizeof(char))))
	{
		it2 = new;
		it = s;
		while (*it)
		{
			if (!to_del(*it))
			{
				*it2 = *it;
				++it2;
			}
			++it;
		}
	}
	return (new);
}
