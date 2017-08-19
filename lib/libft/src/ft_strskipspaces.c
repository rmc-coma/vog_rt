/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strskipspaces.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 08:12:55 by calemany          #+#    #+#             */
/*   Updated: 2015/01/31 08:15:58 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"
#include "ft_string.h"

char	*ft_strskipspaces(char const *s)
{
	while (ft_isspace(*s))
		++s;
	return ((char*)s);
}
