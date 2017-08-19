/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_parse2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 23:30:13 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/08 15:57:06 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "libft.h"

#define FORM_INT_COUNT          13
#define FORM_FUNC_COUNT			2

int	form_parse_textboxes(t_form *form, t_xml_element const *elem)
{
	t_xml_element const *textboxes_elem;
	t_xml_node const	*node;
	int					i;
	int					err;
	t_textbox			*textbox;

	err = 0;
	if (!(textboxes_elem = xml_element_find_child(elem, "textboxes")))
		return (err);
	node = textboxes_elem->children;
	form->n_textboxes = textboxes_elem->child_count;
	form->textboxes = textboxes_new(form->n_textboxes);
	i = -1;
	while (!err && ++i < textboxes_elem->child_count)
	{
		if (node->type == XML_NODE_ELEMENT)
		{
			textbox = textbox_new();
			textbox->pos = form->pos;
			err = textbox_parse(textbox, &node->element, form);
			(!err) ? form->textboxes[i] = textbox : free(textbox);
		}
		++node;
	}
	return (err);
}

int	form_parse_buttons(t_form *form, t_xml_element const *elem)
{
	t_xml_element const *buttons_elem;
	t_xml_node const	*node;
	int					i;
	int					err;
	t_button			*button;

	err = 0;
	if (!(buttons_elem = xml_element_find_child(elem, "buttons")))
		return (err);
	node = buttons_elem->children;
	form->n_buttons = buttons_elem->child_count;
	form->buttons = buttons_new(form->n_buttons);
	i = -1;
	while (!err && ++i < buttons_elem->child_count)
	{
		if (node->type == XML_NODE_ELEMENT)
		{
			button = button_new();
			button->pos = form->pos;
			err = button_parse(button, &node->element);
			(!err) ? form->buttons[i] = button : free(button);
		}
		++node;
	}
	return (err);
}

int	form_parse_values(t_form *form, t_xml_element const *elem)
{
	static char const	*names[FORM_INT_COUNT] = { "width", "height",
		"x", "y", "bg_color_r", "bg_color_g", "bg_color_b", "bg_color_a",
		"f_color_r", "f_color_g", "f_color_b", "f_color_a", "padding"};
	int					err;
	t_ivec2				base;
	GLuint				*values[FORM_INT_COUNT];

	values[0] = (GLuint *)&form->width;
	values[1] = (GLuint *)&form->height;
	values[2] = (GLuint *)&form->pos.x;
	values[3] = (GLuint *)&form->pos.y;
	values[4] = (GLuint *)(&form->bg_color);
	values[5] = (GLuint *)(((GLubyte *)(&form->bg_color)) + 1);
	values[6] = (GLuint *)(((GLubyte *)(&form->bg_color)) + 2);
	values[7] = (GLuint *)(((GLubyte *)(&form->bg_color)) + 3);
	values[8] = (GLuint *)(&form->color);
	values[9] = (GLuint *)(((GLubyte *)(&form->color)) + 1);
	values[10] = (GLuint *)(((GLubyte *)(&form->color)) + 2);
	values[11] = (GLuint *)(((GLubyte *)(&form->color)) + 3);
	values[12] = (GLuint *)&form->padding;
	base = form->pos;
	err = (parse_int_children(elem, FORM_INT_COUNT, names, (int **)values) < 0);
	form->pos.x += base.x;
	form->pos.y += base.y;
	return (err);
}

int	form_parse_text(t_form *form, t_xml_element const *elem)
{
	int					err;
	static char const	*name[1] = {
		"text"
	};
	char				**value[1];

	value[0] = &form->text;
	err = (parse_string_children(elem, 1, name, value) < 0);
	if (!form->text)
		form->text = ft_strdup("Undefined field");
	return (err);
}

int	form_parse_function(t_form *form, t_xml_element const *elem)
{
	static char const	*names[FORM_FUNC_COUNT] = {
		"list", "text"
	};
	static char const	*targets[RACK_VALUE_TYPE_COUNT] = {
		"cameras",
		"objects",
		"lights"
	};
	t_form_type			values[FORM_FUNC_COUNT];
	int					err;
	int					i;

	values[0] = FT_LIST;
	values[1] = FT_TEXT;
	form->type = FT_NONE;
	err = parse_enum_element(xml_element_find_child(elem, "function"),
		FORM_FUNC_COUNT, names, &i);
	form->type = values[i];
	i = 0;
	err = parse_enum_element(xml_element_find_child(elem, "target"),
		RACK_VALUE_TYPE_COUNT, targets, &i);
	form->target = (t_rvalue_type)i;
	return (err);
}
