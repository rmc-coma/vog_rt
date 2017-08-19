/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 18:25:05 by calemany          #+#    #+#             */
/*   Updated: 2014/11/05 18:32:10 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

void	*ft_memalloc(size_t size)
{
	void	*p;

	if (size == 0)
		return (NULL);
	p = malloc(size);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, size);
	return (p);
}
