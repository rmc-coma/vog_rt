/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 17:48:33 by calemany          #+#    #+#             */
/*   Updated: 2015/02/25 18:09:32 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdarg.h>
#include <stdlib.h>

static char	*init_str(char const *s, va_list list)
{
	size_t		size;
	char const	*it;

	size = ft_strlen(s);
	while ((it = va_arg(list, char const*)))
		size += ft_strlen(it);
	++size;
	return ((char*)malloc(size * sizeof(char)));
}

char		*ft_strsum(char const *first, ...)
{
	va_list		list;
	char		*s;
	char		*it;
	char const	*arg;

	va_start(list, first);
	s = init_str(first, list);
	va_end(list);
	va_start(list, first);
	ft_strcpy(s, first);
	it = s + ft_strlen(first);
	while ((arg = va_arg(list, char const*)))
	{
		ft_strcpy(it, arg);
		it += ft_strlen(arg);
	}
	va_end(list);
	return (s);
}
