/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcountend.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 11:36:40 by calemany          #+#    #+#             */
/*   Updated: 2015/03/13 11:38:24 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int		ft_strcountend(char const *s, char const *end, char c)
{
	int		n;

	n = 0;
	while (s < end)
	{
		n += (*s == c);
		++s;
	}
	return (n);
}
