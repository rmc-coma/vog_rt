/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 12:15:50 by calemany          #+#    #+#             */
/*   Updated: 2015/03/04 12:19:48 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_output.h"
#include <stdarg.h>

void	ft_put(char const *s, ...)
{
	va_list		list;

	va_start(list, s);
	ft_put_fd_list(1, s, list);
	va_end(list);
}
