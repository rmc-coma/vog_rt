/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwordsplit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 17:53:36 by calemany          #+#    #+#             */
/*   Updated: 2016/06/23 16:06:07 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"
#include "ft_string.h"
#include <stdlib.h>

static int	word_count(char const *s)
{
	int		size;

	size = 0;
	while (ft_isspace(*s))
		++s;
	while (*s != '\0')
	{
		s = ft_strwordend(s);
		++size;
		while (ft_isspace(*s))
			++s;
	}
	return (size);
}

char		**ft_strwordsplit(char const *s)
{
	char	**words;
	int		size;
	char	**it;

	while (ft_isspace(*s))
		++s;
	size = word_count(s);
	words = (char**)malloc((size + 1) * sizeof(char*));
	it = words;
	while (size--)
	{
		*it = ft_strworddup(s, &s);
		while (ft_isspace(*s))
			++s;
		++it;
	}
	*it = NULL;
	return (words);
}
