/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:21:00 by calemany          #+#    #+#             */
/*   Updated: 2014/11/06 17:35:10 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

static unsigned int	digitcount(int n)
{
	unsigned int count;

	if (n == 0)
		return (1);
	count = 1;
	if (n < 0)
		++count;
	n /= 10;
	while (n != 0)
	{
		++count;
		n /= 10;
	}
	return (count);
}

char				*ft_itoa(int n)
{
	unsigned int	i;
	char			*str;
	unsigned int	len;

	len = digitcount(n);
	str = (char*)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	i = len - 1;
	while (n != 0)
	{
		str[i] = n % 10 + 48;
		n /= 10;
		--i;
	}
	return (str);
}
