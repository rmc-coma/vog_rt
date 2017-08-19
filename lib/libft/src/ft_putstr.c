/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:17:51 by calemany          #+#    #+#             */
/*   Updated: 2015/01/21 16:52:55 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_output.h"

void	ft_putstr(char const *s)
{
	int				n;
	char const		*it;

	it = s;
	n = 0;
	while (*it++ != '\0')
		++n;
	write(1, s, n);
}
