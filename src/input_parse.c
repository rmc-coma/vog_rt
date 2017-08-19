/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 06:15:26 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/01 03:28:43 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "ft_mem.h"
#include <stdlib.h>

static int	parse_keys(t_input *const in, t_xml_element const *elem)
{
	t_xml_element const	*keys_elem;
	t_xml_node const	*node;
	int					i;
	int					err;
	t_key				*key;

	err = 0;
	keys_elem = xml_element_find_child(elem, "keys");
	if (!keys_elem)
		return (0);
	node = keys_elem->children;
	in->n_keys = keys_elem->child_count;
	in->keys = (t_key **)ft_memalloc(sizeof(t_key *) * in->n_keys);
	i = -1;
	while (!err && ++i < keys_elem->child_count)
	{
		if (node->type == XML_NODE_ELEMENT)
		{
			key = key_new();
			err = key_parse(key, &node->element);
			(!err) ? in->keys[i] = key : free(key);
		}
		++node;
	}
	return (err);
}

int			input_parse(t_input *const input, t_xml_element const *elem)
{
	int					err;

	err = parse_keys(input, elem);
	return (err);
}
