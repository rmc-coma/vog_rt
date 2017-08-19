/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locker_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 02:42:00 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/01 04:52:23 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

#define L_F_C		1
#define L_I_C		13

static int	parse_values(t_locker *locker, t_xml_element const *elem)
{
	static char const	*names[L_I_C] = {"width", "height", "x", "y",
		"bg_color_r", "bg_color_g", "bg_color_b", "bg_color_a", "f_color_r",
		"f_color_g", "f_color_b", "f_color_a", "padding"
	};
	GLuint				*values[L_I_C];
	int					err;
	t_ivec2				base;

	values[0] = (GLuint *)&locker->width;
	values[1] = (GLuint *)&locker->height;
	values[2] = (GLuint *)&locker->pos.x;
	values[3] = (GLuint *)&locker->pos.y;
	values[4] = (GLuint *)(&locker->bg_color);
	values[5] = (GLuint *)(((unsigned char *)(&locker->bg_color)) + 1);
	values[6] = (GLuint *)(((unsigned char *)(&locker->bg_color)) + 2);
	values[7] = (GLuint *)(((unsigned char *)(&locker->bg_color)) + 3);
	values[8] = (GLuint *)(&locker->color);
	values[9] = (GLuint *)(((unsigned char *)(&locker->color)) + 1);
	values[10] = (GLuint *)(((unsigned char *)(&locker->color)) + 2);
	values[11] = (GLuint *)(((unsigned char *)(&locker->color)) + 3);
	values[12] = (GLuint *)&locker->padding;
	base = locker->pos;
	err = (parse_int_children(elem, L_I_C, names, (int **)values) < 0);
	locker->pos = ivec2(locker->pos.x + base.x, locker->pos.y + base.y);
	return (err);
}

static int	parse_function(t_locker *locker, t_xml_element const *elem)
{
	static void			*(*funcs[L_F_C])(void *, void *, void *, void *) = {
		FUNC_CAST(&gui_putlist)
	};
	static char const	*names[L_F_C] = {
		"objects"
	};
	int					err;
	int					i;

	err = parse_enum_element(xml_element_find_child(elem, "function"),
			L_F_C, names, &i);
	if (!err)
	{
		locker->draw_func = funcs[i];
		if (parse_string_element(xml_element_find_child(elem, "text"),
								&locker->text))
			locker->text = ft_strdup("Undefined field");
	}
	return (err);
}

int			locker_parse(t_locker *locker, t_xml_element const *elem)
{
	int					err;

	err = parse_values(locker, elem);
	if (!err)
		err = parse_function(locker, elem);
	return (0);
}
