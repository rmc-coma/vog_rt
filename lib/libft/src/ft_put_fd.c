/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 12:13:58 by calemany          #+#    #+#             */
/*   Updated: 2015/03/23 12:39:15 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_output.h"
#include "ft_string.h"
#include <stdarg.h>
#include <unistd.h>

void	ft_put_fd_list(int fd, char const *s, va_list list)
{
	char const	*it;

	while (*s && (it = ft_strchr(s, '%')))
	{
		write(fd, s, it - s);
		++it;
		if (*it == 's')
			ft_putstr_fd(va_arg(list, char const*), fd);
		else if (*it == 'd')
			ft_putint_fd(va_arg(list, int), fd);
		else if (*it == 'u')
			ft_putuint_fd(va_arg(list, unsigned int), fd);
		else if (*it == 'p')
			ft_putaddr_fd(va_arg(list, void const*), fd);
		else if (*it == '\0')
			break ;
		s = it + 1;
	}
	if (*s)
		ft_putstr_fd(s, fd);
}

void	ft_put_fd(int fd, char const *s, ...)
{
	va_list		list;

	va_start(list, s);
	ft_put_fd_list(fd, s, list);
	va_end(list);
}
