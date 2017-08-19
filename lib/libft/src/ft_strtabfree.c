/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 16:23:55 by calemany          #+#    #+#             */
/*   Updated: 2015/02/27 16:25:20 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

void	ft_strtabfree(char **tab)
{
	char	**it;

	if (tab)
	{
		it = tab;
		while (*it)
			free(*it++);
		free(tab);
	}
}
