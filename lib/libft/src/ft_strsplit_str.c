/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 04:32:42 by calemany          #+#    #+#             */
/*   Updated: 2015/01/07 04:40:23 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

static char			*nextword(char const *s, char const *c)
{
	while (ft_strchr(c, *s) && *s != '\0')
		++s;
	return ((char*)s);
}

static char			*getword(char const *s, char const *c)
{
	unsigned int	len;

	len = 0;
	while (!ft_strchr(c, s[len]) && s[len] != '\0')
		++len;
	return (ft_strsub(s, 0, len));
}

static unsigned int	wordcount(char const *s, char const *c)
{
	unsigned int n;

	while (ft_strchr(c, *s) && *s != '\0')
		++s;
	n = 0;
	while (*s != '\0')
	{
		++n;
		while (!ft_strchr(c, *s) && *s != '\0')
			++s;
		while (ft_strchr(c, *s) && *s != '\0')
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

char				**ft_strsplit_str(char const *s, char const *c)
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
		while (!ft_strchr(c, *s) && *s != '\0')
			++s;
		++i;
	}
	return (split);
}
