/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_token_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 15:44:42 by calemany          #+#    #+#             */
/*   Updated: 2016/09/26 18:09:05 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xml_token.h"
#include "xml_error.h"
#include "xml_word.h"

#include "libft.h"

char const				*xml_token_keyword(t_xml_token_type type)
{
	static char const		*keywords[XML_KEYWORD_COUNT] = {
		"<!--", "-->", "</", "/>", "<", ">", "=", "'", "\""
	};
	unsigned int			i;

	i = (unsigned int)type;
	if (i < XML_KEYWORD_COUNT)
		return (keywords[i]);
	else
		return (0);
}

static int				str_keyword_cmp(char const *str, char const *keyword)
{
	int		i;

	i = 0;
	while (str[i] == keyword[i] && keyword[i] != '\0')
		++i;
	if (keyword[i] != '\0')
		return (0);
	return (i);
}

static t_xml_token_type	keywords_cmp(char const *str, int *size)
{
	static t_xml_token_type const	types[] = {
		XML_TOKEN_COM_BEG,
		XML_TOKEN_COM_END,
		XML_TOKEN_OEND,
		XML_TOKEN_CEND,
		XML_TOKEN_OPEN,
		XML_TOKEN_CLOSE,
		XML_TOKEN_ASSIGN,
		XML_TOKEN_QUOTE,
		XML_TOKEN_DQUOTE
	};
	int								i;
	int								length;

	i = 0;
	while (i < XML_KEYWORD_COUNT)
	{
		if ((length = str_keyword_cmp(str, xml_token_keyword(types[i]))))
		{
			*size = length;
			return (types[i]);
		}
		++i;
	}
	return (XML_TOKEN_NULL);
}

static void				set_string_token(t_xml_token *tok, char const *str)
{
	int		size;

	tok->begin = str;
	if (ft_isspace(*str))
	{
		tok->type = XML_TOKEN_SPACE;
		while (ft_isspace(*str))
			++str;
		tok->end = str;
	}
	else
	{
		tok->type = XML_TOKEN_STRING;
		while (*str && !ft_isspace(*str)
				&& keywords_cmp(str, &size) == XML_TOKEN_NULL)
			++str;
		tok->end = str;
	}
}

void					xml_token_set(t_xml_token *tok, char const *str)
{
	int			size;

	tok->type = keywords_cmp(str, &size);
	if (tok->type == XML_TOKEN_NULL)
		set_string_token(tok, str);
	else
	{
		tok->begin = str;
		tok->end = str + size;
	}
}
