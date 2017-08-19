/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_node.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 14:21:45 by calemany          #+#    #+#             */
/*   Updated: 2016/09/26 14:21:46 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XML_NODE_H
# define XML_NODE_H

# include "xml_element.h"
# include "xml_content.h"
# include "xml_node_type.h"
# include "xml_error.h"

typedef union			u_xml_node
{
	t_xml_node_type		type;
	t_xml_element		element;
	t_xml_content		content;
}						t_xml_node;

void					xml_node_set_content(t_xml_node *node, char const *s);
void					xml_node_free(t_xml_node *node);
t_xml_error				xml_node_parse(t_xml_node *node,
		t_xml_token const *toks, t_xml_token const **end);
int						xml_node_begin(t_xml_token const *tok);

#endif
