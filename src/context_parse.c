/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 02:33:13 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/01 00:57:54 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context.h"

#define CONTEXT_INT_COUNT	4

int			context_parse(t_context *context, t_xml_element const *elem)
{
	static char const	*names[CONTEXT_INT_COUNT] = {
		"width", "height", "x", "y"
	};
	int					*values[CONTEXT_INT_COUNT];
	int					err;

	values[0] = &context->width;
	values[1] = &context->height;
	values[2] = &context->pos.x;
	values[3] = &context->pos.y;
	err = (parse_int_children(elem, CONTEXT_INT_COUNT, names, values) < 0);
	return (err);
}
