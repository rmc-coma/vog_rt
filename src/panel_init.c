/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panel_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 02:02:14 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/08 17:03:14 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "libft.h"

t_panel	*panel_new(void)
{
	return ((t_panel *)ft_memalloc(sizeof(t_panel)));
}

t_panel	*panel_init(t_panel *const panel)
{
	ft_bzero((void *)panel, sizeof(t_panel));
	return (panel);
}
