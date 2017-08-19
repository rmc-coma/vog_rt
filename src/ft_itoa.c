/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:51:24 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/03 05:34:53 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "libft.h"
#include <stdlib.h>
#include <math.h>

#include <stdio.h>

static size_t	ft_dgtcnt(int n)
{
	int				i;

	i = 0;
	if (!n)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char			sgn;
	int				i;
	unsigned int	ncpy;
	char			*str;

	sgn = n >= 0 ? 0 : 1;
	i = ft_dgtcnt(n);
	ncpy = sgn ? (unsigned int)-n : (unsigned int)n;
	str = (char *)malloc(sizeof(char) * (i + 1 + sgn));
	if (str == NULL)
		return (NULL);
	if (sgn)
	{
		str[0] = '-';
		i++;
	}
	str[i] = 0;
	if (!n)
		str[0] = '0';
	while (ncpy)
	{
		str[--i] = ncpy % 10 + 48;
		ncpy /= 10;
	}
	return (str);
}

char			*ft_itoal(int n, char *const str)
{
	char			sgn;
	int				i;
	unsigned int	ncpy;

	sgn = n >= 0 ? 0 : 1;
	i = ft_dgtcnt(n);
	ncpy = sgn ? (unsigned int)-n : (unsigned int)n;
	if (str == NULL)
		return (NULL);
	if (sgn)
	{
		str[0] = '-';
		i++;
	}
	str[i] = 0;
	if (!n)
		str[0] = '0';
	while (ncpy)
	{
		str[--i] = ncpy % 10 + 48;
		ncpy /= 10;
	}
	return (str);
}

char			*ft_ftoal(float f, char *const str)
{
	int		i;
	int		ep;

	ep = (int)floor((double)f);
	if (ep < 0)
		ep += 1;
	i = 0;
	if (f < 0.0f && f > -1.0f)
		str[i++] = '-';
	ft_itoal(ep, &str[i]);
	while (str[i])
		++i;
	str[i] = '.';
	f -= (float)ep;
	f *= 100.0f;
	ep = (int)floor((double)f);
	if (ep < 0)
		ep = ~ep - 1;
	if (ep < 10)
		str[++i] = '0';
	ft_itoal(ep, &str[++i]);
	return (str);
}

float			ft_atof(char *str)
{
	int				tmp;
	int				i;
	unsigned int	d;
	float			c;
	char			*dec;

	i = 0;
	while (str[i] && str[i] != '.')
		++i;
	if (str[i] != '.')
		return ((float)ft_atoi(str));
	str[i] = 0;
	dec = &(str[i + 1]);
	tmp = i;
	i = 0;
	while (dec[i])
		++i;
	c = (float)pow(10.0, (double)i);
	i = ft_atoi(str);
	d = ft_atoi(dec);
	str[tmp] = '.';
	return (str[0] != '-' ? (float)i + (float)d / c : (float)i - (float)d / c);
}
