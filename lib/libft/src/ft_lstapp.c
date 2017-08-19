/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstapp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 05:11:15 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/02/28 19:50:51 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstapp(t_list **alst, t_list *new)
{
	t_list *lst;

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
