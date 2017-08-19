/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreach.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 11:25:02 by calemany          #+#    #+#             */
/*   Updated: 2015/01/27 11:25:50 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"
#include "ft_string.h"

char	*ft_strreach(char const *s, char const *reach)
{
	while (!ft_strchr(reach, *s))
		++s;
	return ((char*)s);
}
