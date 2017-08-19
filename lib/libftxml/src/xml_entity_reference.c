/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_entity_reference.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 10:56:48 by calemany          #+#    #+#             */
/*   Updated: 2016/09/26 17:23:16 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xml_entity_reference.h"
#include "libft.h"

static int	copy_ref(char **dst, char const *ref_start, int ref_size)
{
	static char *const	entity_refs[] = {
		"lt", "gt", "amp", "apos", "quot", 0
	};
	static char const	char_refs[] = { '<', '>', '&', '\'', '"' };
	static char const	size_refs[] = { 2, 2, 3, 4, 4 };
	int					i;

	i = 0;
	while (entity_refs[i])
	{
		if (ref_size == size_refs[i]
				&& !ft_strncmp(ref_start, entity_refs[i], ref_size))
		{
			*(*dst)++ = char_refs[i];
			return (1);
		}
		++i;
	}
	*(*dst)++ = '&';
	return (0);
}

static int	get_ref_range(char const *str, char **ref_start, char **ref_end)
{
	char	*it;
	char	*it2;

	it = ft_strchr(str, '&');
	if (it)
	{
		++it;
		it2 = ft_strchr(it, ';');
		if (it2)
		{
			*ref_start = it;
			*ref_end = it2;
			return (1);
		}
	}
	return (0);
}

char		*xml_replace_entity_refs(char *str)
{
	char	*sub;
	char	*it;
	char	*ref_start;
	char	*ref_end;

	sub = str;
	it = sub;
	while (*str != '\0' && get_ref_range(str, &ref_start, &ref_end))
	{
		ft_strncpy(it, str, ref_start - 1 - str);
		it += ref_start - str - 1;
		if (copy_ref(&it, ref_start, ref_end - ref_start))
			str = ref_end + 1;
		else
			str = ref_start;
	}
	ft_strcpy(it, str);
	return (sub);
}
