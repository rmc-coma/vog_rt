/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 14:22:01 by calemany          #+#    #+#             */
/*   Updated: 2015/02/23 14:26:37 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_output.h"
#include <stdarg.h>

void	ft_putnstr_list(va_list list)
{
	ft_putnstr_fd_list(1, list);
}

void	ft_putnstr(char const *s, ...)
{
	va_list		list;

	ft_putstr(s);
	va_start(list, s);
	ft_putnstr_list(list);
	va_end(list);
}
