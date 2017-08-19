/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panel_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 03:59:54 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/13 15:58:18 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "ft_mem.h"

#define PANEL_INT_COUNT	8

static int	parse_textboxes(t_panel *panel, t_xml_element const *elem)
{
	t_xml_element const	*textboxes_elem;
	t_xml_node const	*node;
	int					i;
	int					err;
	t_textbox			*textbox;

	err = 0;
	if (!(textboxes_elem = xml_element_find_child(elem, "textboxes")))
		return (0);
	node = textboxes_elem->children;
	panel->n_textboxes = textboxes_elem->child_count;
	panel->textboxes = textboxes_new(panel->n_textboxes);
	i = -1;
	while (!err && ++i < textboxes_elem->child_count)
	{
		if (node->type == XML_NODE_ELEMENT)
		{
			textbox = textbox_new();
			textbox->pos = panel->pos;
			err = textbox_parse(textbox, &node->element, NULL);
			(!err) ? panel->textboxes[i] = textbox : free(textbox);
		}
		++node;
	}
	return (err);
}

static int	parse_buttons(t_panel *panel, t_xml_element const *elem)
{
	t_xml_element const	*buttons_elem;
	t_xml_node const	*node;
	int					i;
	int					err;
	t_button			*button;

	err = 0;
	if (!(buttons_elem = xml_element_find_child(elem, "buttons")))
		return (0);
	node = buttons_elem->children;
	panel->n_buttons = buttons_elem->child_count;
	panel->buttons = buttons_new(panel->n_buttons);
	i = -1;
	while (!err && ++i < buttons_elem->child_count)
	{
		if (node->type == XML_NODE_ELEMENT)
		{
			button = button_new();
			button->pos = panel->pos;
			err = button_parse(button, &node->element);
			(!err) ? panel->buttons[i] = button : free(button);
		}
		++node;
	}
	return (err);
}

static int	parse_forms(t_panel *panel, t_xml_element const *elem)
{
	int					err;
	t_xml_element const	*forms_elem;
	t_xml_node const	*node;
	int					i;
	t_form				*form;

	err = 0;
	if (!(forms_elem = xml_element_find_child(elem, "forms")))
		return (0);
	node = forms_elem->children;
	panel->n_forms = forms_elem->child_count;
	panel->forms = forms_new(panel->n_forms);
	i = -1;
	while (!err && ++i < forms_elem->child_count)
	{
		if (node->type == XML_NODE_ELEMENT)
		{
			form = form_new();
			form->pos = panel->pos;
			err = form_parse(form, &node->element, panel);
			(!err) ? panel->forms[i] = form : free(form);
		}
		++node;
	}
	return (err);
}

static int	parse_lockers(t_panel *panel, t_xml_element const *elem)
{
	int					err;
	t_xml_element const	*lockers_elem;
	t_xml_node const	*node;
	int					i;
	t_locker			*locker;

	err = 0;
	if (!(lockers_elem = xml_element_find_child(elem, "lists")))
		return (0);
	node = lockers_elem->children;
	panel->n_lockers = lockers_elem->child_count;
	panel->lockers = lockers_new(panel->n_lockers);
	i = -1;
	while (!err && ++i < lockers_elem->child_count)
	{
		if (node->type == XML_NODE_ELEMENT)
		{
			locker = locker_new();
			locker->pos = panel->pos;
			err = locker_parse(locker, &node->element);
			(!err) ? panel->lockers[i] = locker : free(locker);
		}
		++node;
	}
	return (err);
}

int			panel_parse(t_panel *panel, t_xml_element const *elem)
{
	static char const	*names[PANEL_INT_COUNT] = {
		"width", "height", "x", "y", "bg_color_r", "bg_color_g",
		"bg_color_b", "bg_color_a"
	};
	int					*values[PANEL_INT_COUNT];
	int					err;

	values[0] = &panel->width;
	values[1] = &panel->height;
	values[2] = &panel->pos.x;
	values[3] = &panel->pos.y;
	values[4] = (int *)(&panel->bg_color);
	values[5] = (int *)(((unsigned char *)(&panel->bg_color)) + 1);
	values[6] = (int *)(((unsigned char *)(&panel->bg_color)) + 2);
	values[7] = (int *)(((unsigned char *)(&panel->bg_color)) + 3);
	panel_init(panel);
	if (!(err = (parse_int_children(elem, PANEL_INT_COUNT, names, values) < 0)))
		if (!(err = parse_textboxes(panel, elem)))
			if (!(err = parse_buttons(panel, elem)))
				if (!(err = parse_forms(panel, elem)))
					err = parse_lockers(panel, elem);
	return (err);
}
