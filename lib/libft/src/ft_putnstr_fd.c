/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 14:11:43 by calemany          #+#    #+#             */
/*   Updated: 2015/02/23 14:22:23 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_output.h"

void	ft_putnstr_fd_list(int fd, va_list list)
{
	char const	*it;

	while ((it = va_arg(list, char const*)))
		ft_putstr_fd(it, fd);
}

void	ft_putnstr_fd(int fd, ...)
{
	va_list		list;

	va_start(list, fd);
	ft_putnstr_fd_list(fd, list);
	va_end(list);
}
