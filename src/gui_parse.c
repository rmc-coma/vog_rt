/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 02:41:20 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/03 03:51:09 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "xml_parsing.h"
#include "libftxml.h"

static int	parse_gui_frame(t_gui *gui, t_xml_element const *elem)
{
	t_xml_element const		*child;
	int						err;

	err = 0;
	child = xml_element_find_child(elem, "frame");
	if (child)
	{
		gui_frame_init(gui);
		err = gui_frame_parse(gui, child);
	}
	return (err);
}

int			gui_parse(t_gui *gui, t_xml_element const *elem)
{
	int						err;

	err = parse_gui_frame(gui, elem);
	return (err);
}
