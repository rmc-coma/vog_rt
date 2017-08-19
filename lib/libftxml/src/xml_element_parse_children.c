/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_element_parse_children.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 14:20:02 by calemany          #+#    #+#             */
/*   Updated: 2016/09/26 17:11:55 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xml_element.h"
#include "xml_node.h"
#include "xml_error.h"
#include "xml_node_vector.h"

#include "libft.h"

t_xml_error		xml_element_parse_children(t_xml_element *elem,
		t_xml_token const *toks, t_xml_token const **end)
{
	t_xml_error		err;
	t_xml_node		node;

	err = xml_token_list_skip_comments(toks, &toks);
	if (!err)
		err = (toks != 0) ? XML_SUCCESS : xml_error_eoi();
	while (!err && xml_node_begin(toks))
	{
		err = xml_node_parse(&node, toks, &toks);
		if (!err)
			err = xml_element_add_node(elem, &node);
		if (!err)
			err = xml_token_list_skip_comments(toks, &toks);
		if (!err && !toks)
			err = xml_error_eoi();
	}
	*end = toks;
	return (err);
}
