/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 14:21:28 by calemany          #+#    #+#             */
/*   Updated: 2016/07/09 11:30:10 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strappend(char **dst, char const *to_append)
{
	char	*str;

	str = ft_strjoin(*dst, to_append);
	free(*dst);
	*dst = str;
	return (*dst);
}
