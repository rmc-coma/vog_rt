/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_parsing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 22:37:34 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/02/28 19:28:37 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XML_PARSING_H
# define XML_PARSING_H

# include "libftxml.h"

int				float_parse(char const *str, float *result);
int				int_parse(char const *str, int *result);
int				string_parse(char const *str, char **result);
int				parse_float_element(t_xml_element const *elem, float *result);
int				parse_string_element(t_xml_element const *elem, char **result);
int				parse_int_element(t_xml_element const *elem, int *result);
int				parse_enum_element(t_xml_element const *elem, int count,
				char const **choices, int *index);
int				parse_float_children(t_xml_element const *elem, int count,
				char const **names, float **result);
int				parse_float_array(t_xml_element const *elem, int count,
				char const **names, float *array);
int				parse_int_children(t_xml_element const *elem, int count,
				char const **names, int **result);
int				parse_string_children(t_xml_element const *elem, int count,
				char const **names, char ***result);
t_xml_element	*xml_element_find_child(t_xml_element const *elem,
				char const *name);
int				parse_bool_element(t_xml_element const *elem, int *bool);

#endif
