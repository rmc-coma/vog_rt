/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strskip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 11:21:08 by calemany          #+#    #+#             */
/*   Updated: 2015/01/27 11:25:59 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"
#include "ft_string.h"

char	*ft_strskip(char const *s, char const *skip)
{
	while (ft_strchr(skip, *s))
		++s;
	return ((char*)s);
}
