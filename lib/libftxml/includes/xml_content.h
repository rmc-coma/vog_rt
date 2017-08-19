/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_content.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 14:21:20 by calemany          #+#    #+#             */
/*   Updated: 2016/09/26 18:01:27 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XML_CONTENT_H
# define XML_CONTENT_H

# include "xml_node_type.h"
# include "xml_error.h"
# include "xml_token.h"

typedef struct		s_xml_content
{
	t_xml_node_type	type;
	char			*str;
}					t_xml_content;

void				xml_content_set(t_xml_content *c, char *s);
void				xml_content_free(t_xml_content *c);
t_xml_error			xml_content_from_token_list(t_xml_content *c,
		t_xml_token const *toks, t_xml_token const **end);

#endif
