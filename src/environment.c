/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 14:19:59 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/10/04 20:55:13 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

t_environment	*environment_new(void)
{
	t_environment	*new;

	if (!(new = (t_environment *)malloc(sizeof(t_environment))))
		return (NULL);
	return (new);
}

int				environment_init(t_environment *const env)
{
	if (!env)
		return (ERR_INVALID_PARAM);
	return (NO_ERROR);
}
