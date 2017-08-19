/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_error.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 14:21:40 by calemany          #+#    #+#             */
/*   Updated: 2016/09/26 17:08:00 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XML_ERROR_H
# define XML_ERROR_H

# define XML_SUCCESS 0u

typedef enum			e_xml_error_type
{
	XML_ERROR_NULL,
	XML_ERROR_MEMORY,
	XML_ERROR_QUOTE,
	XML_ERROR_EL_NAME,
	XML_ERROR_UNEXPECTED_EOI,
	XML_ERROR_UNEXPECTED_TOK,
	XML_ERROR_NO_EOI,
	XML_ERROR_COUNT
}						t_xml_error_type;

typedef unsigned int	t_xml_error;

t_xml_error				xml_error_make(t_xml_error_type type,
		unsigned int line_no);
t_xml_error				xml_error_memory(void);
t_xml_error				xml_error_eoi(void);
t_xml_error				xml_error_token(unsigned int line_no);
void					xml_error_get(t_xml_error err, t_xml_error_type *type,
		unsigned int *line_no);
t_xml_error				xml_error_set_line(t_xml_error err,
		unsigned int line_no);
void					xml_error_print(t_xml_error err);

#endif
