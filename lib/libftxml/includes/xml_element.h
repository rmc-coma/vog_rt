/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_element.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 14:21:28 by calemany          #+#    #+#             */
/*   Updated: 2016/09/26 17:56:19 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XML_ELEMENT_H
# define XML_ELEMENT_H

# include "xml_node_type.h"
# include "xml_token.h"
# include "xml_error.h"
# include "xml_node_vector.h"

union u_xml_node;

typedef struct				s_xml_element
{
	enum e_xml_node_type	type;
	char					*name;
	union u_xml_node		*children;
	int						child_count;
	t_xml_node_vector		node_vector;
}							t_xml_element;

t_xml_element				*xml_element_init(t_xml_element *e);
t_xml_error					xml_element_from_token(t_xml_element *elem,
		t_xml_token const *tok);
t_xml_error					xml_element_parse(t_xml_element *elem,
		t_xml_token const *toks, t_xml_token const **end);
void						xml_element_free(t_xml_element *e);
t_xml_error					xml_element_add_node(t_xml_element *elem,
		union u_xml_node *n);
int							xml_element_begin(t_xml_token const *tok);
t_xml_error					xml_element_parse_children(t_xml_element *elem,
		t_xml_token const *toks, t_xml_token const **end);
t_xml_error					xml_element_parse_attributes(t_xml_element *elem,
		t_xml_token const *toks, t_xml_token const **end);

#endif
