/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 14:20:28 by calemany          #+#    #+#             */
/*   Updated: 2016/09/26 17:53:40 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xml_node.h"
#include "xml_token.h"
#include "xml_element.h"
#include "xml_entity_reference.h"
#include "xml_content.h"
#include "xml_error.h"

#include "libft.h"

t_xml_error	xml_node_parse(t_xml_node *node, t_xml_token const *toks,
		t_xml_token const **end)
{
	t_xml_error		err;

	err = xml_token_list_skip_comments(toks, &toks);
	if (!err && !toks)
		err = xml_error_eoi();
	if (!err)
	{
		if (toks->type == XML_TOKEN_OPEN)
		{
			xml_element_init(&node->element);
			err = xml_element_parse(&node->element, toks, &toks);
		}
		else if (toks->type == XML_TOKEN_STRING)
			err = xml_content_from_token_list(&node->content, toks, &toks);
		else
			err = xml_error_token(toks->line_no);
	}
	*end = toks;
	return (err);
}

int			xml_node_begin(t_xml_token const *tok)
{
	int		b;

	b = (tok != 0)
		&& (tok->type == XML_TOKEN_STRING || xml_element_begin(tok));
	return (b);
}

void		xml_node_free(t_xml_node *node)
{
	if (node->type == XML_NODE_ELEMENT)
		xml_element_free(&node->element);
	else if (node->type == XML_NODE_CONTENT)
		xml_content_free(&node->content);
}
