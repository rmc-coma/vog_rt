/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 14:19:22 by calemany          #+#    #+#             */
/*   Updated: 2016/09/26 18:01:46 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xml_content.h"
#include "xml_entity_reference.h"
#include "xml_token.h"

#include "libft.h"

t_xml_error	xml_content_from_token_list(t_xml_content *c,
		t_xml_token const *toks, t_xml_token const **end)
{
	t_xml_token const	*it;
	t_xml_token const	*str_end;
	t_xml_error			err;
	char				*str;

	err = xml_token_check_type(toks, XML_TOKEN_STRING);
	if (err)
		return (err);
	it = toks;
	while (it && it->type == XML_TOKEN_STRING)
	{
		str_end = it;
		xml_token_list_skip_space(str_end->next, &it);
	}
	str = ft_strsub(toks->begin, 0, str_end->end - toks->begin);
	xml_content_set(c, str);
	*end = it;
	return (XML_SUCCESS);
}

void		xml_content_set(t_xml_content *c, char *s)
{
	c->type = XML_NODE_CONTENT;
	c->str = xml_replace_entity_refs(s);
}

void		xml_content_free(t_xml_content *c)
{
	free(c->str);
	c->str = 0;
}
