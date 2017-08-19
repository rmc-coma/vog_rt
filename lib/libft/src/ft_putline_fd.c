/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putline_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 12:15:07 by calemany          #+#    #+#             */
/*   Updated: 2015/02/23 13:26:41 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_output.h"
#include <unistd.h>

void	ft_putline_fd(char const *s, int fd)
{
	size_t		size;
	char const	*it;

	while (*s)
	{
		size = 0;
		it = s;
		while (*it && *it != '\n')
		{
			++size;
			++it;
		}
		write(fd, s, size);
		if (*it)
		{
			write(fd, "\\n", 2);
			++it;
		}
		s = it;
	}
}
