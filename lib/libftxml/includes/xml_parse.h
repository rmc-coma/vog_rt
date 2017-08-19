/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_parse.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 14:22:05 by calemany          #+#    #+#             */
/*   Updated: 2016/09/27 17:13:09 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XML_PARSE_H
# define XML_PARSE_H

# include "xml_error.h"

struct s_xml_element;

t_xml_error		xml_parse(char const *str, struct s_xml_element *elem);

#endif
