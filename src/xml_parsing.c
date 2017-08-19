/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 22:36:06 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/13 15:43:55 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xml_parsing.h"
#include "double_parse.h"
#include "libft.h"
#include "libftxml.h"

int				parse_bool_element(t_xml_element const *elem, int *bool)
{
	static char const	*names[2] = {"false", "true"};

	return (parse_enum_element(elem, 2, names, bool));
}

t_xml_element	*xml_element_find_child(t_xml_element const *elem,
		char const *name)
{
	int					i;
	t_xml_node const	*node;

	node = elem->children;
	i = 0;
	while (i < elem->child_count)
	{
		if (node->type == XML_NODE_ELEMENT
				&& !ft_strcmp(node->element.name, name))
			return ((t_xml_element *)&node->element);
		++node;
		++i;
	}
	return (0);
}
