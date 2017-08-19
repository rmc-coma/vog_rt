/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_error_make.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 17:00:21 by calemany          #+#    #+#             */
/*   Updated: 2016/09/26 18:02:11 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xml_error.h"

t_xml_error		xml_error_memory(void)
{
	return (xml_error_make(XML_ERROR_MEMORY, 0));
}

t_xml_error		xml_error_eoi(void)
{
	return (xml_error_make(XML_ERROR_UNEXPECTED_EOI, 0));
}

t_xml_error		xml_error_token(unsigned int line_no)
{
	return (xml_error_make(XML_ERROR_UNEXPECTED_TOK, line_no));
}

t_xml_error		xml_error_make(t_xml_error_type type, unsigned int line_no)
{
	unsigned int	i;

	i = (unsigned int)type & 0x000000ff;
	i |= line_no << 8;
	return ((t_xml_error)i);
}
