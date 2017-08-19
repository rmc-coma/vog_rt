/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rack_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 07:20:18 by jleu              #+#    #+#             */
/*   Updated: 2017/03/01 07:20:19 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

t_rack	*rack_new(void)
{
	return ((t_rack *)malloc(sizeof(t_rack)));
}

t_rack	*rack_init(t_rack *const rack)
{
	ft_bzero((void *)rack, sizeof(t_rack));
	return (rack);
}
