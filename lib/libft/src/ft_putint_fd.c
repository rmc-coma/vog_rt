/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 16:01:43 by calemany          #+#    #+#             */
/*   Updated: 2015/03/07 16:10:25 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_output.h"

void		ft_putint_fd(int n, int fd)
{
	if (n >= 0)
		ft_putuint_fd((unsigned int)n, fd);
	else
	{
		ft_putchar_fd('-', fd);
		ft_putuint_fd(-(unsigned int)n, fd);
	}
}
