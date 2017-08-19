/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 01:22:43 by jleu              #+#    #+#             */
/*   Updated: 2017/03/01 01:23:38 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_mem.h"

#include <stdlib.h>

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (lst == NULL)
		return (NULL);
	if (content == NULL)
	{
		lst->content = NULL;
		lst->content_size = 0;
	}
	else
	{
		lst->content = ft_memdup((void *)content, content_size);
		lst->content_size = content_size;
	}
	lst->next = NULL;
	return (lst);
}

void	ft_lstapp(t_list **alst, t_list *new)
{
	t_list	*lst;

	if (*alst != NULL)
	{
		lst = *alst;
		while ((*alst)->next != NULL)
			*alst = (*alst)->next;
		(*alst)->next = new;
		*alst = lst;
	}
	else
	{
		*alst = new;
	}
}
