/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 12:23:35 by calemany          #+#    #+#             */
/*   Updated: 2014/11/15 12:27:10 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_lstchr(t_list *lst, void *content, int (*equal)(void*, void*))
{
	if (lst == NULL)
		return (NULL);
	if (equal(content, lst->content))
		return (lst);
	return (ft_lstchr(lst->next, content, equal));
}
