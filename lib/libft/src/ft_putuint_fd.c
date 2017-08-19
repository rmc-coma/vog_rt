/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 16:05:48 by calemany          #+#    #+#             */
/*   Updated: 2015/03/23 15:14:39 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_output.h"

static void	put_pos(unsigned int u, int fd)
{
	if (u)
	{
		put_pos(u / 10, fd);
		ft_putchar_fd(u % 10 + '0', fd);
	}
}

void		ft_putuint_fd(unsigned int u, int fd)
{
	if (u == 0)
		ft_putchar_fd('0', fd);
	else
		put_pos(u, fd);
}
