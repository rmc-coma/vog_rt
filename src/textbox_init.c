/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textbox_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 02:05:07 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/02 04:47:29 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "libft.h"

t_textbox	*textbox_new(void)
{
	return ((t_textbox *)ft_memalloc(sizeof(t_textbox)));
}

t_textbox	*textbox_init(t_textbox *const textbox)
{
	ft_bzero((void *)textbox, sizeof(t_textbox));
	return (textbox);
}

t_textbox	**textboxes_new(int n_textboxes)
{
	return ((t_textbox **)ft_memalloc(sizeof(t_textbox *) * n_textboxes));
}
