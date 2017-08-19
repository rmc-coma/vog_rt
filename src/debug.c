/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 01:13:28 by jleu              #+#    #+#             */
/*   Updated: 2017/03/01 01:13:29 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "parameters.h"
#include "ft_str.h"
#include <unistd.h>

void	debug_put_str(const char *const str)
{
	if (!DEBUG_ACTIVE)
		return ;
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}

void	debug_put_int(const int nbr)
{
	char	*tmp;

	if (!DEBUG_ACTIVE)
		return ;
	tmp = ft_itoa(nbr);
	write(1, tmp, ft_strlen(tmp));
	write(1, "\n", 1);
	free(tmp);
}

void	debug_put_str_int(const char *const str, const int nbr)
{
	char *tmp;

	if (!DEBUG_ACTIVE)
		return ;
	write(1, str, ft_strlen(str));
	write(1, ": ", 2);
	tmp = ft_itoa(nbr);
	write(1, tmp, ft_strlen(tmp));
	write(1, "\n", 1);
	free(tmp);
}

void	debug_put_str_str(const char *const str1, const char *const str2)
{
	write(1, str1, ft_strlen(str1));
	write(1, " ", 1);
	write(1, str2, ft_strlen(str2));
	write(1, "\n", 1);
}
