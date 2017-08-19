/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwordcmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 12:13:37 by calemany          #+#    #+#             */
/*   Updated: 2015/02/09 15:23:55 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"
#include "ft_string.h"

char	*ft_strwordcmp(char const *str, char const *word)
{
	char const	*it;

	it = ft_strwordend(str);
	if (ft_strncmp(str, word, it - str))
		return ((char*)it);
	return (NULL);
}
