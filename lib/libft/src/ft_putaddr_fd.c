/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 12:35:57 by calemany          #+#    #+#             */
/*   Updated: 2015/03/23 14:49:48 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_output.h"
#include <unistd.h>

static void	hex_rec(unsigned long long i, int fd)
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

void		ft_putaddr_fd(void const *i, int fd)
{
	write(fd, "0x", 2);
	if (i)
		hex_rec((unsigned long long)i, fd);
	else
		write(fd, "0", 1);
}
