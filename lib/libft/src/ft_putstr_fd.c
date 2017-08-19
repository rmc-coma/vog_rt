/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:24:04 by calemany          #+#    #+#             */
/*   Updated: 2015/01/21 16:53:05 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_output.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int				n;
	char const		*it;

	it = s;
	n = 0;
	while (*it++ != '\0')
		++n;
	write(fd, s, n);
}
