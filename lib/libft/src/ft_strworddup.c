/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strworddup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 12:38:41 by calemany          #+#    #+#             */
/*   Updated: 2015/02/23 09:40:11 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"
#include "ft_string.h"

char		*ft_strworddup(char const *s, char const **end)
{
	char const	*str;
	char const	*s2;
	char		*ret;

	s = ft_strskipspaces(s);
	str = s;
	s = ft_strwordend(str);
	if (s > str && ft_isquote(*str))
	{
		s2 = s;
		ret = (str <= s2) ? ft_strsub2(str, s2) : ft_strdup("");
	}
	else
		ret = ft_strsub2(str, s);
	if (end)
		*end = ft_strskipspaces(s);
	return (ret);
}
