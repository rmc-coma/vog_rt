/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 03:38:09 by jleu              #+#    #+#             */
/*   Updated: 2017/03/01 04:09:49 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "libft.h"

t_key	*key_new(void)
{
	return ((t_key *)ft_memalloc(sizeof(t_key)));
}

t_key	*key_init(t_key *const key)
{
	ft_bzero((void *)key, sizeof(t_key));
	return (key);
}

t_key	*key_set(t_key *const key, const Uint8 scancode,
		void *(*func)(void *const, const Uint32, void *const),
		const t_key_type type)
{
	key->scancode = scancode;
	key->func = func;
	key->type = type;
	return (key);
}
