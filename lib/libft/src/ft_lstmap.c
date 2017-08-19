/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 19:36:10 by calemany          #+#    #+#             */
/*   Updated: 2015/03/04 10:02:38 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

static void	del_one(void *content, size_t content_size)
{
	free(content);
	return ;
	content_size = (int)content_size;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*map;

	if (lst)
	{
		map = ft_lstnew(lst->content, lst->content_size);
		if (map)
		{
			map->next = ft_lstmap(lst->next, f);
			if (lst->next && !map->next)
				ft_lstdelone(&map, del_one);
			else
			{
				f(map);
				return (map);
			}
		}
	}
	return (NULL);
}
