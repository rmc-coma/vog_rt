/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 10:10:23 by calemany          #+#    #+#             */
/*   Updated: 2015/02/18 10:11:11 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int		ft_strisnbr(char const *str)
{
	if (*str == '+' || *str == '-')
		++str;
	while (*str != '\0')
	{
		if (!ft_isdigit(*str))
			return (0);
		++str;
	}
	return (1);
}
