/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 01:26:56 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/03 06:46:08 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "ft_str.h"
#include "window.h"

#define BUTTON_INT_COUNT		13
#define B_C					1

static int	parse_values(t_button *b, t_xml_element const *elem)
{
	static char const	*names[BUTTON_INT_COUNT] = {
		"width", "height", "x", "y", "bg_color_r", "bg_color_g", "bg_color_b",
		"bg_color_a", "f_color_r", "f_color_g", "f_color_b", "f_color_a",
		"padding"
	};
	int const			*values[BUTTON_INT_COUNT] = {
		&b->width, &b->height, &b->pos.x, &b->pos.y, (int *)(&b->bg_color),
		(int *)(((unsigned char *)(&b->bg_color)) + 1),
		(int *)(((unsigned char *)(&b->bg_color)) + 2),
		(int *)(((unsigned char *)(&b->bg_color)) + 3), (int *)(&b->color),
		(int *)(((unsigned char *)(&b->color)) + 1),
		(int *)(((unsigned char *)(&b->color)) + 2),
		(int *)(((unsigned char *)(&b->color)) + 3), (int *)(&b->padding)
	};
	int					err;
	t_ivec2				base;

	base = b->pos;
	err = (parse_int_children(elem, BUTTON_INT_COUNT, names,
				(int **)values) < 0);
	b->pos.x += base.x;
	b->pos.y += base.y;
	return (err);
}

static int	parse_functions(t_button *button, t_xml_element const *elem)
{
	static void			*(*cfuncs[B_C])(void *, void *, void *, void *) = {
		FUNC_CAST(&window_vsync_switch)
	};
	static char const	*names[B_C] = {
		"vsync"
	};
	int					err;
	int					i;

	err = parse_enum_element(xml_element_find_child(elem, "function"),
		B_C, names, &i);
	if (!err)
	{
		button->click_func = cfuncs[i];
		if (parse_string_element(xml_element_find_child(elem,
			"text"), &button->text))
			button->text = ft_strdup("Undefined field");
	}
	if ((i >= B_C || i < 0) && err)
		return (0);
	else
		button->type = (t_button_type)i;
	return (err);
}

int			button_parse(t_button *button, t_xml_element const *elem)
{
	int					err;

	err = parse_values(button, elem);
	if (!err)
		err = parse_functions(button, elem);
	return (err);
}
