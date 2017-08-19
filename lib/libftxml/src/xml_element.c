/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 14:19:35 by calemany          #+#    #+#             */
/*   Updated: 2017/03/13 16:13:40 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xml_element.h"
#include "xml_node.h"
#include "xml_token.h"
#include "xml_node_vector.h"
#include "xml_word.h"

#include "libft.h"

#include <stdlib.h>

t_xml_element	*xml_element_init(t_xml_element *e)
{
	e->type = XML_NODE_ELEMENT;
	e->name = 0;
	e->children = 0;
	e->child_count = 0;
	xml_node_vector_init(&e->node_vector);
	return (e);
}

void			xml_element_free(t_xml_element *e)
{
	free(e->name);
	e->name = 0;
	if (e->children)
		xml_node_free(e->children);
	e->children = (void *)0;
	e->child_count = 0;
	xml_node_vector_free(&e->node_vector);
}

t_xml_error		xml_element_from_token(t_xml_element *elem,
		t_xml_token const *tok)
{
	t_xml_error		err;

	free(elem->name);
	err = xml_token_check_type(tok, XML_TOKEN_STRING);
	if (!err && xml_check_element_name(tok->begin, tok->end))
		err = xml_error_make(XML_ERROR_EL_NAME, tok->line_no);
	if (!err)
	{
		elem->name = ft_strsub(tok->begin, 0, tok->end - tok->begin);
		if (!elem->name)
			err = xml_error_memory();
	}
	else
		elem->name = 0;
	return (err);
}

t_xml_error		xml_element_add_node(t_xml_element *elem, t_xml_node *n)
{
	t_xml_error	er;

	er = xml_node_vector_push_back(&elem->node_vector, n);
	if (!er)
	{
		elem->children = elem->node_vector.tab;
		elem->child_count = elem->node_vector.size;
	}
	else
		xml_element_free(elem);
	return (er);
}

int				xml_element_begin(t_xml_token const *tok)
{
	int		b;

	b = (tok != 0)
		&& (tok->type == XML_TOKEN_OPEN);
	return (b);
}
