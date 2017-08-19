/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 12:08:46 by calemany          #+#    #+#             */
/*   Updated: 2014/11/13 17:48:17 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

static char			*nextword(char const *s, char c)
{
	while (*s == c && *s != '\0')
		++s;
	return ((char*)s);
}

static char			*getword(char const *s, char c)
{
	unsigned int	len;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		++len;
	return (ft_strsub(s, 0, len));
}

static unsigned int	wordcount(char const *s, char c)
{
	unsigned int n;

	while (*s == c && *s != '\0')
		++s;
	n = 0;
	while (*s != '\0')
	{
		++n;
		while (*s != c && *s != '\0')
			++s;
		while (*s == c && *s != '\0')
			++s;
	}
	return (n);
}

static void			freesplit(char **split, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i < n)
		free(split[i++]);
	free(split);
}

char				**ft_strsplit(char const *s, char c)
{
	char			**split;
	unsigned int	count;
	unsigned int	i;

	count = wordcount(s, c);
	split = (char**)malloc((count + 1) * sizeof(char*));
	split[count] = NULL;
	i = 0;
	while (i < count)
	{
		s = nextword(s, c);
		split[i] = getword(s, c);
		if (split[i] == NULL)
		{
			freesplit(split, i);
			return (NULL);
		}
		while (*s != c && *s != '\0')
			++s;
		++i;
	}
	return (split);
}
