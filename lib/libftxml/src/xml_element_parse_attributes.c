/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_element_parse_attributes.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 14:19:54 by calemany          #+#    #+#             */
/*   Updated: 2016/09/27 15:17:59 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xml_element.h"
#include "xml_error.h"
#include "xml_node.h"
#include "xml_token.h"

#include "libft.h"

#include <stdlib.h>

static t_xml_error	get_quote_end(t_xml_token const *toks,
		t_xml_token const **end)
{
	t_xml_token_type	type;
	t_xml_token const	*it;

	if (!toks)
		return (xml_error_eoi());
	if (toks->type != XML_TOKEN_QUOTE && toks->type != XML_TOKEN_DQUOTE)
		return (xml_error_token(toks->line_no));
	type = toks->type;
	it = toks->next;
	while (it && it->type != type)
	{
		if (it->type != XML_TOKEN_STRING && it->type != XML_TOKEN_QUOTE
				&& it->type != XML_TOKEN_DQUOTE && it->type != XML_TOKEN_SPACE)
			return (xml_error_token(it->line_no));
		it = it->next;
	}
	if (!it)
		return (xml_error_eoi());
	*end = it;
	return (XML_SUCCESS);
}

static t_xml_error	set_attr_node(t_xml_node *node, t_xml_token const *name_tok,
		t_xml_token const *quote_beg, t_xml_token const *quote_end)
{
	t_xml_error	err;
	char		*content;

	node->type = XML_NODE_ELEMENT;
	xml_element_init(&node->element);
	err = xml_element_from_token(&node->element, name_tok);
	if (err)
		return (err);
	node->element.child_count = 1;
	node->element.children = (t_xml_node*)malloc(sizeof(t_xml_node));
	if (!node->element.children)
		return (xml_error_memory());
	content = ft_strsub(quote_beg->end, 0, quote_end->begin - quote_beg->end);
	if (content)
		xml_content_set(&node->element.children->content, content);
	else
		return (xml_error_memory());
	return (XML_SUCCESS);
}

t_xml_error			xml_element_parse_attributes(t_xml_element *elem,
		t_xml_token const *toks, t_xml_token const **end)
{
	t_xml_token	const	*name;
	t_xml_node			node;
	t_xml_error			err;
	t_xml_token const	*quote_end;

	err = XML_SUCCESS;
	xml_token_list_skip_space(toks, &toks);
	while (!err && toks && toks->type == XML_TOKEN_STRING)
	{
		name = toks;
		toks = toks->next;
		if (!(err = xml_token_check_type(toks, XML_TOKEN_ASSIGN)))
		{
			toks = toks->next;
			err = get_quote_end(toks, &quote_end);
			if (!err)
				err = set_attr_node(&node, name, toks, quote_end);
			if (!err)
				err = xml_element_add_node(elem, &node);
			if (!err)
				xml_token_list_skip_space(quote_end->next, &toks);
		}
	}
	*end = toks;
	return (err);
}
