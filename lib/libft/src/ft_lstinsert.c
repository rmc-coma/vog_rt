/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 15:01:09 by calemany          #+#    #+#             */
/*   Updated: 2014/11/22 18:22:06 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstinsert(t_list *elem, t_list **lst,
		int (*cmp)(t_list *left, t_list *right))
{
	if (*lst == NULL)
	{
		elem->next = NULL;
		*lst = elem;
	}
	else
	{
		if (cmp(elem, *lst))
		{
			elem->next = *lst;
			*lst = elem;
		}
		else
			ft_lstinsert(elem, &((*lst)->next), cmp);
	}
}
