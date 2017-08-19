/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:26:20 by calemany          #+#    #+#             */
/*   Updated: 2015/03/04 16:54:37 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_output.h"

static void	putnbr_pos_fd(long n, int fd)
{
	if (n != 0)
	{
		putnbr_pos_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n > 0)
		putnbr_pos_fd(n, fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		putnbr_pos_fd(-(long)n, fd);
	}
	else
		ft_putchar_fd('0', fd);
}
