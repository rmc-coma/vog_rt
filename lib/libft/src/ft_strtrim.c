/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 20:35:47 by calemany          #+#    #+#             */
/*   Updated: 2015/02/12 12:24:44 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strtrim(char const *s)
{
	char const	*begin;
	char const	*end;

	begin = s;
	while (*begin == ' ' || *begin == '\n' || *begin == '\t')
		++begin;
	if (*begin == '\0')
		return (ft_strnew(0));
	end = begin + 1;
	while (*end != '\0')
		++end;
	--end;
	while (*end == ' ' || *end == '\n' || *end == '\t')
		--end;
	return (ft_strsub(begin, 0, end - begin + 1));
}
