/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 14:57:50 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/01 01:30:26 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s || !*s)
		return (0);
	i = 0;
	while (*s++)
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	s1len;

	s1len = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * (s1len + 1));
	if (str == NULL)
		return (NULL);
	str[s1len] = 0;
	while (s1len--)
		str[s1len] = s1[s1len];
	return (str);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	size_t	strlen;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	strlen = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (strlen + 1));
	if (str == NULL)
		return (NULL);
	str[strlen] = 0;
	i = 0;
	while ((str[i] = *s1++))
		i++;
	while ((str[i] = *s2++))
		i++;
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str && *str != c)
		str++;
	return (*str == c ? str : 0);
}

char	*ft_strnew(size_t size)
{
	char *str;

	str = (char *)malloc(sizeof(char) * ++size);
	if (str == NULL)
		return (NULL);
	while (size--)
		str[size] = 0;
	return (str);
}
