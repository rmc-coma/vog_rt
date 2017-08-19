/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_element_parse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 14:19:48 by calemany          #+#    #+#             */
/*   Updated: 2016/09/27 15:17:29 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xml_element.h"
#include "xml_content.h"
#include "xml_node.h"
#include "xml_node_type.h"
#include "xml_token.h"
#include "xml_error.h"

#include "libft.h"

#include <stdlib.h>

static t_xml_error	parse_element_end(t_xml_element *elem,
		t_xml_token const *toks, t_xml_token const **end)
{
	t_xml_error	err;

	err = xml_token_list_skip_comments(toks, &toks);
	if (!err)
		err = xml_token_check_type(toks, XML_TOKEN_OEND);
	if (!err)
		err = xml_token_check_type(toks->next, XML_TOKEN_STRING);
	if (!err)
	{
		toks = toks->next;
		if (!err && ft_strncmp(elem->name, toks->begin,
					toks->end - toks->begin) != 0)
			err = xml_error_make(XML_ERROR_EL_NAME, toks->line_no);
		if (!err)
		{
			toks = toks->next;
			err = xml_token_check_type(toks, XML_TOKEN_CLOSE);
			if (!err)
				toks = toks->next;
		}
	}
	*end = toks;
	return (err);
}

t_xml_error			xml_element_parse(t_xml_element *elem,
		t_xml_token const *toks, t_xml_token const **end)
{
	t_xml_error			err;

	if (!(err = xml_token_list_skip_comments(toks, &toks)))
		err = xml_token_check_type(toks, XML_TOKEN_OPEN);
	if (!err)
		err = xml_element_from_token(elem, toks->next);
	if (!err)
		err = xml_element_parse_attributes(elem, toks->next->next, &toks);
	if (!err)
	{
		if (!toks)
			err = xml_error_eoi();
		else if (toks->type == XML_TOKEN_CLOSE)
		{
			err = xml_element_parse_children(elem, toks->next, &toks);
			if (!err)
				err = parse_element_end(elem, toks, &toks);
		}
		else if (toks->type == XML_TOKEN_CEND)
			toks = toks->next;
		else
			err = xml_error_token(toks->line_no);
	}
	*end = toks;
	return (err);
}
