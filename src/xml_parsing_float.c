/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_parsing_float.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 22:38:01 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/02/27 22:38:04 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xml_parsing.h"
#include "double_parse.h"

#include "libft.h"
#include "libftxml.h"

int				float_parse(char const *str, float *result)
{
	double		d;
	int			err;

	err = double_parse(str, &d);
	if (!err)
		*result = (float)d;
	return (err);
}

int				parse_float_element(t_xml_element const *elem, float *result)
{
	if (elem->child_count == 1 && elem->children->type == XML_NODE_CONTENT)
		return (float_parse(elem->children->content.str, result));
	else
		return (1);
}

int				parse_float_children(t_xml_element const *elem, int count,
		char const **names, float **result)
{
	int					i;
	t_xml_element const	*child;
	int					found_count;

	i = 0;
	found_count = 0;
	while (i < count)
	{
		child = xml_element_find_child(elem, names[i]);
		if (child)
		{
			++found_count;
			if (parse_float_element(child, result[i]))
				return (-1);
		}
		++i;
	}
	return (found_count);
}

int				parse_float_array(t_xml_element const *elem, int count,
		char const **names, float *array)
{
	int					i;
	t_xml_element const	*child;
	int					found_count;

	i = 0;
	found_count = 0;
	while (i < count)
	{
		child = xml_element_find_child(elem, names[i]);
		if (child)
		{
			++found_count;
			if (parse_float_element(child, array + i))
				return (-1);
		}
		++i;
	}
	return (found_count);
}
