/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 23:23:00 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/01 03:24:09 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "libft.h"
#include "gui.h"

#include <stdio.h>

t_input	*input_init(t_input *const input)
{
	ft_bzero((void *)input, sizeof(t_input));
	return (input);
}
