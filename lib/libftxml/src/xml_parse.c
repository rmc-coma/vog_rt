/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 14:20:42 by calemany          #+#    #+#             */
/*   Updated: 2016/09/26 18:07:05 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xml_element.h"
#include "xml_token.h"
#include "xml_error.h"

#include "libft.h"

t_xml_error		xml_parse(char const *str, t_xml_element *elem)
{
	t_xml_token			*tokens;
	t_xml_token const	*end;
	t_xml_error			err;

	tokens = 0;
	err = xml_token_list_set(&tokens, str);
	if (!err)
		err = xml_element_parse(elem, tokens, &end);
	if (!err)
		err = xml_token_list_skip_comments(end, &end);
	if (!err && end != 0)
		err = xml_error_eoi();
	xml_token_list_free(&tokens);
	return (err);
}
