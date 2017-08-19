/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_frame_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 02:41:59 by jleu              #+#    #+#             */
/*   Updated: 2017/03/13 18:03:51 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "ft_mem.h"
#include <stdlib.h>

#define FRAME_INT_COUNT	4

static int	parse_panels(t_frame *f, t_xml_element const *elem)
{
	t_xml_element const *panels_elem;
	t_xml_node const	*node;
	int					i;
	int					err;
	t_panel				*panel;

	err = 0;
	panels_elem = xml_element_find_child(elem, "panels");
	if (!panels_elem)
		return (0);
	node = panels_elem->children;
	f->n_panels = panels_elem->child_count;
	f->panels = (t_panel **)ft_memalloc(sizeof(t_panel *) * f->n_panels);
	i = -1;
	while (!err && ++i < panels_elem->child_count)
	{
		if (node->type == XML_NODE_ELEMENT)
		{
			panel = panel_new();
			err = panel_parse(panel, &node->element);
			(!err) ? f->panels[i] = panel : free(panel);
		}
		++node;
	}
	return (err);
}

int			gui_frame_parse(t_gui *gui, t_xml_element const *elem)
{
	static char const	*names[FRAME_INT_COUNT] = {
		"width", "height", "x", "y"
	};
	int					*values[FRAME_INT_COUNT];
	int					err;

	values[0] = &gui->frame.width;
	values[1] = &gui->frame.height;
	values[2] = &gui->frame.pos.x;
	values[3] = &gui->frame.pos.y;
	err = (parse_int_children(elem, FRAME_INT_COUNT, names, values) < 0);
	if (!err)
		err = parse_panels(&gui->frame, elem);
	return (err);
}
