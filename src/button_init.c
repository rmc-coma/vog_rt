/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 02:03:13 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/01 23:28:21 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "libft.h"

t_button	*button_new(void)
{
	return ((t_button *)ft_memalloc(sizeof(t_button)));
}

t_button	*button_init(t_button *const button)
{
	ft_bzero((void *)button, sizeof(t_button));
	return (button);
}

t_button	**buttons_new(int n_buttons)
{
	return ((t_button **)ft_memalloc(sizeof(t_button *) * n_buttons));
}
