/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 02:24:51 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/02 04:15:18 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "libft.h"

t_form	*form_new(void)
{
	return ((t_form *)ft_memalloc(sizeof(t_form)));
}

t_form	*form_init(t_form *const form)
{
	ft_bzero((void *)form, sizeof(t_form));
	return (form);
}

t_form	**forms_new(int n_forms)
{
	return ((t_form **)ft_memalloc(sizeof(t_form *) * n_forms));
}
