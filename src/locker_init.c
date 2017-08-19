/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locker_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 02:50:53 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/02 04:16:05 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

t_locker	*locker_new(void)
{
	return ((t_locker *)ft_memalloc(sizeof(t_locker)));
}

t_locker	*locker_init(t_locker *const locker)
{
	ft_bzero((void *)locker, sizeof(t_locker));
	return (locker);
}

t_locker	**lockers_new(int n_lockers)
{
	return ((t_locker **)ft_memalloc(sizeof(t_locker *) * n_lockers));
}
