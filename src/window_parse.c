/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 00:19:39 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/02/28 21:26:27 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

#define WINDOW_INT_COUNT	4

static int	parse_gui(t_window *window, t_xml_element const *elem)
{
	t_xml_element const	*child;
	int					err;

	gui_init(&window->gui, &window->context, &window->width, &window->height);
	err = 0;
	child = xml_element_find_child(elem, "gui");
	if (child)
		err = gui_parse(&window->gui, child);
	return (err);
}

static int	parse_context(t_window *window, t_xml_element const *elem)
{
	t_xml_element const	*child;
	int					err;

	context_init(&window->context);
	err = 0;
	child = xml_element_find_child(elem, "context");
	if (child)
		err = context_parse(&window->context, child);
	return (err);
}

int			window_parse(t_window *window, t_xml_element const *elem)
{
	static char const	*names[WINDOW_INT_COUNT] = {
		"width", "height", "x", "y"
	};
	int					*values[WINDOW_INT_COUNT];
	int					err;

	values[0] = &window->width;
	values[1] = &window->height;
	values[2] = &window->pos.x;
	values[3] = &window->pos.y;
	err = parse_gui(window, elem);
	if (!err)
		err = (parse_int_children(elem, WINDOW_INT_COUNT, names, values) < 0);
	if (!err)
		err = parse_context(window, elem);
	return (err);
}
