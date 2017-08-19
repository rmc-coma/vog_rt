/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 19:22:00 by calemany          #+#    #+#             */
/*   Updated: 2014/11/14 19:25:06 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (*alst != NULL)
		ft_lstdel(&((*alst)->next), del);
	ft_lstdelone(alst, del);
}
