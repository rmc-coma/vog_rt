/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 12:19:38 by calemany          #+#    #+#             */
/*   Updated: 2016/07/09 12:47:25 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strsep(char **stringp, const char *delim)
{
	char	*it;
	char	*token;

	token = *stringp;
	it = *stringp;
	while (*it && !ft_strchr(delim, *it))
		++it;
	if (*it)
		*stringp = it + 1;
	else
		*stringp = it;
	*it = '\0';
	return (token);
}
