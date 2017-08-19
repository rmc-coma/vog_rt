/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 02:07:06 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/02 03:42:22 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

int			form_parse(t_form *form, t_xml_element const *elem,
				t_panel *parent)
{
	int					err;

	err = form_parse_values(form, elem);
	if (!err)
		err = form_parse_text(form, elem);
	if (!err)
		err = form_parse_buttons(form, elem);
	if (!err)
		err = form_parse_textboxes(form, elem);
	if (!err)
		err = form_parse_function(form, elem);
	form->parent = parent;
	return (err);
}
