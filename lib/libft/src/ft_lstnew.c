/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 19:02:40 by calemany          #+#    #+#             */
/*   Updated: 2015/01/13 08:55:29 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

static void	*private_memcpy(void *dst, const void *src, size_t n)
{
	size_t i;

	i = 0;
	while (i != n)
	{
		((char*)dst)[i] = ((char*)src)[i];
		++i;
	}
	return (dst);
}

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lst;

	lst = (t_list*)malloc(sizeof(t_list));
	if (lst != NULL)
	{
		lst->content_size = content_size;
		if (content_size != 0)
		{
			lst->content = malloc(content_size);
			if (lst->content != NULL)
				private_memcpy(lst->content, content, content_size);
			else
			{
				free(lst);
				lst = NULL;
			}
		}
		else
			lst->content = NULL;
	}
	return (lst);
}
