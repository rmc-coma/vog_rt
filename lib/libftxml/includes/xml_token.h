/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_token.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/28 17:55:01 by calemany          #+#    #+#             */
/*   Updated: 2016/09/26 16:29:20 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XML_TOKEN_H
# define XML_TOKEN_H

# include "xml_error.h"

# define XML_KEYWORD_COUNT 9

typedef enum			e_xml_token_type
{
	XML_TOKEN_COM_BEG,
	XML_TOKEN_COM_END,
	XML_TOKEN_OEND,
	XML_TOKEN_CEND,
	XML_TOKEN_OPEN,
	XML_TOKEN_CLOSE,
	XML_TOKEN_ASSIGN,
	XML_TOKEN_QUOTE,
	XML_TOKEN_DQUOTE,
	XML_TOKEN_STRING,
	XML_TOKEN_SPACE,
	XML_TOKEN_COUNT,
	XML_TOKEN_NULL,
}						t_xml_token_type;

typedef struct			s_xml_token
{
	t_xml_token_type	type;
	char const			*begin;
	char const			*end;
	unsigned int		line_no;
	struct s_xml_token	*next;
}						t_xml_token;

t_xml_token				*xml_token_init(t_xml_token *tok);
char const				*xml_token_keyword(t_xml_token_type type);
void					xml_token_set(t_xml_token *tok, char const *str);
t_xml_token				*xml_token_new(void);
t_xml_error				xml_token_check_type(t_xml_token const *toks,
		t_xml_token_type type);
void					xml_token_list_skip_space(t_xml_token const *toks,
		t_xml_token const **end);
t_xml_error				xml_token_list_skip_comments(t_xml_token const *toks,
		t_xml_token const **end);
void					xml_token_list_free(t_xml_token **list);
t_xml_error				xml_token_list_set(t_xml_token **list, char const *str);

#endif
