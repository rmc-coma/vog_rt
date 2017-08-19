/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 02:50:13 by jleu              #+#    #+#             */
/*   Updated: 2017/03/01 02:51:05 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "ft_str.h"
#include <stdio.h>

t_gui	*gui_putstr(t_gui *const gui, const char *const str,
		const GLuint *const color, t_ivec2 *const pos)
{
	if (str)
		gui_write(gui, str, *color, pos);
	return (gui);
}

t_gui	*gui_putint(t_gui *const gui, const int n, const GLuint *const color,
		t_ivec2 *const pos)
{
	char	str[32];

	gui_write(gui, ft_itoal(n, &str[0]), *color, pos);
	return (gui);
}

t_gui	*gui_putlist(t_gui *const gui, t_list *elem, const GLuint *const color,
		t_ivec2 *const pos)
{
	while (elem)
	{
		gui_write(gui, elem->content, *color, pos);
		pos->y += gui->fontdata.height;
		elem = elem->next;
	}
	return (gui);
}
