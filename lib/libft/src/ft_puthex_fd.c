/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 12:33:56 by calemany          #+#    #+#             */
/*   Updated: 2015/03/23 14:49:36 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_output.h"
#include <unistd.h>

static void	hex_rec(unsigned int i, int fd)
{
	char	c;

	if (i)
	{
		hex_rec(i / 16, fd);
		i = i % 16;
		if (i < 10)
			c = i + '0';
		else
			c = i + 'A' - 10;
		write(fd, &c, 1);
	}
}

void		ft_puthex_fd(unsigned int i, int fd)
{
	write(fd, "0x", 2);
	if (i)
		hex_rec(i, fd);
	else
		write(fd, "0", 1);
}
