/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 22:01:06 by calemany          #+#    #+#             */
/*   Updated: 2014/11/06 15:15:35 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static int	ft_p_isspace(char c)
{
	int b;

	b = c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ';
	return (b);
}

int			ft_atoi(const char *str)
{
	int n;
	int	sign;

	while (ft_p_isspace(*str))
		++str;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		++str;
	}
	else if (*str == '+')
		++str;
	n = 0;
	while (ft_isdigit(*str))
	{
		n = 10 * n + *str - '0';
		++str;
	}
	n *= sign;
	return (n);
}
