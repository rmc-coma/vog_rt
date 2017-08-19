/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_parsing_children.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 21:22:05 by jleu              #+#    #+#             */
/*   Updated: 2017/03/13 15:54:08 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xml_parsing.h"

int	parse_int_children(t_xml_element const *elem, int count,
	char const **names, int **result)
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
			if (parse_int_element(child, result[i]))
				return (-1);
		}
		++i;
	}
	return (found_count);
}

int	parse_string_children(t_xml_element const *elem, int count,
	char const **names, char ***result)
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
			if (parse_string_element(child, result[i]))
				return (-1);
		}
		++i;
	}
	return (found_count);
}
