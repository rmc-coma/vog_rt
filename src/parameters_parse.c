/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters_parse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 06:15:09 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/08 15:57:28 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parameters.h"
#include "environment.h"
#include "xml_parsing.h"
#include "libftxml.h"

#include <stdio.h>

static int	parse_window(t_environment *env, t_xml_element const *elem)
{
	t_xml_element const	*child;
	int					err;
	t_window			*window;

	err = 0;
	child = xml_element_find_child(elem, "window");
	if (child)
	{
		window = window_init(&env->window);
		err = window_parse(window, child);
	}
	return (err);
}

static int	parse_input(t_environment *env, t_xml_element const *elem)
{
	t_xml_element const	*child;
	int					err;
	t_input				*input;

	err = 0;
	child = xml_element_find_child(elem, "input");
	if (child)
	{
		input = input_init(&env->input);
		err = input_parse(input, child);
	}
	return (err);
}

int			parameters_parse(t_environment *env, t_xml_element const *elem)
{
	int		err;

	err = parse_window(env, elem);
	if (!err)
		err = parse_input(env, elem);
	return (err);
}
