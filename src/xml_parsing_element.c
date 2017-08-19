/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_parsing_element.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 22:36:40 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/13 15:51:50 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xml_parsing.h"
#include "libft.h"

int				parse_int_element(t_xml_element const *elem, int *result)
{
	if (elem->child_count == 1 && elem->children->type == XML_NODE_CONTENT)
		return (int_parse(elem->children->content.str, result));
	else
		return (1);
}

int				parse_string_element(t_xml_element const *elem, char **result)
{
	if (elem->child_count == 1 && elem->children->type == XML_NODE_CONTENT)
		return (string_parse(elem->children->content.str, result));
	else
		return (1);
}

int				parse_enum_element(t_xml_element const *elem, int count,
		char const **choices, int *index)
{
	int			i;
	char const	*str;

	if (elem->child_count == 1 && elem->children->type == XML_NODE_CONTENT)
	{
		str = elem->children->content.str;
		i = 0;
		while (i < count)
		{
			if (!ft_strcmp(str, choices[i]))
			{
				*index = i;
				return (0);
			}
			++i;
		}
	}
	return (1);
}
