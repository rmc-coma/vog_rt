/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toksplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 11:48:53 by calemany          #+#    #+#             */
/*   Updated: 2015/02/18 12:59:33 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"
#include <stdlib.h>

static int	token_count(char const *s, char const **sep)
{
	int				n;
	char const		*it;

	n = 0;
	while (*s)
	{
		while (ft_tokget(s, sep, &it))
		{
			s = it;
			++n;
		}
		s = ft_toksearch(s, sep);
		n += (*s != '\0');
	}
	return (n);
}

char		**ft_toksplit(char const *s, char const **sep)
{
	char		**tab;
	char		**it;
	int			n;

	n = token_count(s, sep);
	tab = (char**)malloc((n + 1) * sizeof(*tab));
	tab[n] = NULL;
	it = tab;
	while (*it)
		*it++ = ft_tokdup(s, sep, &s);
	return (tab);
}
