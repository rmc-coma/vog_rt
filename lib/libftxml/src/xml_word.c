/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 14:21:13 by calemany          #+#    #+#             */
/*   Updated: 2016/09/27 17:19:21 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xml_word.h"

#include "libft.h"

int		xml_check_element_name(char const *str, char const *end)
{
	if (ft_isalpha(*str) || *str == '_' || *str == ':')
	{
		++str;
		while (str != end && (ft_isalnum(*str) || ft_strchr(".-_:", *str)))
			++str;
	}
	else
		return (1);
	return (str != end);
}
