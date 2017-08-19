/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/28 17:55:24 by calemany          #+#    #+#             */
/*   Updated: 2016/09/26 18:08:36 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xml_token.h"
#include "xml_entity_reference.h"
#include "libft.h"

#include <stdlib.h>

t_xml_token		*xml_token_init(t_xml_token *tok)
{
	tok->type = XML_TOKEN_NULL;
	tok->begin = 0;
	tok->end = 0;
	tok->next = 0;
	return (tok);
}

t_xml_token		*xml_token_new(void)
{
	t_xml_token		*tok;

	tok = (t_xml_token*)malloc(sizeof(t_xml_token));
	if (tok)
		xml_token_init(tok);
	return (tok);
}

t_xml_error		xml_token_check_type(t_xml_token const *toks,
		t_xml_token_type type)
{
	if (toks)
	{
		if (toks->type == type)
			return (XML_SUCCESS);
		else
			return (xml_error_token(toks->line_no));
	}
	else
		return (xml_error_eoi());
}
