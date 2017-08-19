/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 00:08:18 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/01/22 05:18:14 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "ft_str.h"

char	*set_exec_dir(char *exec_dir, const char *const exec_filename)
{
	int	i;
	int	length;

	length = ft_strlen(exec_filename);
	while (length > 0 && exec_filename[length] != '/')
		--length;
	exec_dir = ft_strnew(length + 1);
	i = 0;
	while (i < length)
	{
		exec_dir[i] = exec_filename[i];
		++i;
	}
	exec_dir[i] = '/';
	return (exec_dir);
}
