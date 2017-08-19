/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_token_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 14:20:53 by calemany          #+#    #+#             */
/*   Updated: 2016/09/26 18:09:22 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xml_token.h"
#include "xml_error.h"
#include "xml_word.h"

#include "libft.h"

#include <stdlib.h>

static unsigned int	count_lf(char const *str, char const *end)
{
	int		i;

	i = 0;
	while (str < end)
	{
		if (*str == '\n')
			++i;
		++str;
	}
	return (i);
}

t_xml_error			xml_token_list_set(t_xml_token **list, char const *str)
{
	t_xml_token		**tail;
	unsigned int	line_no;

	line_no = 1;
	*list = 0;
	tail = list;
	while (*str)
	{
		*tail = xml_token_new();
		if (!*tail)
		{
			xml_token_list_free(list);
			return (xml_error_memory());
		}
		(*tail)->line_no = line_no;
		xml_token_set(*tail, str);
		line_no += count_lf(str, (*tail)->end);
		str = (*tail)->end;
		tail = &(*tail)->next;
	}
	return (XML_SUCCESS);
}

void				xml_token_list_skip_space(t_xml_token const *toks,
		t_xml_token const **end)
{
	if (toks && toks->type == XML_TOKEN_SPACE)
		toks = toks->next;
	*end = toks;
}

t_xml_error			xml_token_list_skip_comments(t_xml_token const *toks,
		t_xml_token const **end)
{
	t_xml_error			e;
	t_xml_token const	*com_end;

	e = XML_SUCCESS;
	xml_token_list_skip_space(toks, &toks);
	while (!e && toks && toks->type == XML_TOKEN_COM_BEG)
	{
		com_end = toks->next;
		while (com_end && com_end->type != XML_TOKEN_COM_END)
			com_end = com_end->next;
		if (!com_end)
			e = xml_error_make(XML_ERROR_UNEXPECTED_EOI, 0);
		else if (ft_strnstr(toks->end, "--", com_end->begin - toks->end))
			e = xml_error_token(toks->next->line_no);
		else
			xml_token_list_skip_space(com_end->next, &toks);
	}
	*end = toks;
	return (e);
}

void				xml_token_list_free(t_xml_token **list)
{
	t_xml_token		*it;
	t_xml_token		*to_free;

	it = *list;
	while (it)
	{
		to_free = it;
		it = it->next;
		free(to_free);
	}
	*list = 0;
}
