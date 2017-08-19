/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_parsing_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 22:41:11 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/13 15:51:25 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xml_parsing.h"
#include "double_parse.h"
#include "libft.h"
#include "libftxml.h"

int	int_parse(char const *str, int *result)
{
	*result = ft_atoi(str);
	return (0);
}

int	string_parse(char const *str, char **result)
{
	*result = ft_strdup(str);
	return (0);
}
