/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinpath.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 12:26:54 by calemany          #+#    #+#             */
/*   Updated: 2015/01/27 19:02:54 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"
#include "ft_string.h"

char		*ft_strjoinpath(char const *path, char const *name)
{
	size_t	size;
	char	*new_path;

	if (path == NULL)
		if (name == NULL)
			return (ft_strdup(""));
		else
			return (ft_strdup(name));
	else if (name == NULL)
		return (ft_strdup(path));
	size = ft_strlen(path);
	if (path[size - 1] != '/')
	{
		new_path = (char*)malloc((size + 2 + ft_strlen(name)) * sizeof(char));
		if (new_path == NULL)
			return (NULL);
		ft_strcpy(new_path, path);
		new_path[size] = '/';
		ft_strcpy(new_path + size + 1, name);
	}
	else
		new_path = ft_strjoin(path, name);
	return (new_path);
}
