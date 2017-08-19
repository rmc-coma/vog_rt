/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 14:20:21 by calemany          #+#    #+#             */
/*   Updated: 2016/09/26 17:01:09 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xml_error.h"

#include "libft.h"

void			xml_error_get(t_xml_error err, t_xml_error_type *type,
		unsigned int *line_no)
{
	unsigned int	i;

	i = (unsigned int)err;
	if (type)
		*type = i & 0x000000ff;
	if (line_no)
		*line_no = i >> 8;
}

t_xml_error		xml_error_set_line(t_xml_error err, unsigned int line_no)
{
	err = (err & 0x000000ff) + (line_no << 8);
	return (err);
}

void			xml_error_print(t_xml_error err)
{
	char const			*msg[] = {
		"memory allocation failed",
		"no closing quotation mark",
		"invalid element name",
		"unexpected end of input",
		"unexpected token",
		"expected end of input"
	};
	t_xml_error_type	type;
	unsigned int		line;
	unsigned int		i;

	xml_error_get(err, &type, &line);
	i = (unsigned int)type;
	if (i > 0 && i < XML_ERROR_COUNT)
	{
		ft_putstr_fd(msg[i - 1], 2);
		if (line > 0)
		{
			ft_putstr_fd(", line ", 2);
			ft_putnbr_fd(line, 2);
		}
	}
	else
		ft_putstr_fd("unknown error", 2);
}
