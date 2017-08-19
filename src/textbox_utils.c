/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textbox_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 02:42:07 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/02/28 22:58:25 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "ft_str.h"
#include "libft.h"

t_textbox	*textbox_append(t_textbox *const textbox, const char entry)
{
	char		tmp[32];
	char		in;
	char		*out;

	in = '\0';
	if (textbox->type == TT_DATA)
	{
		if (textbox->text)
		{
			ft_strcpy(&tmp[0], textbox->text);
			in = (char)ft_strlen(textbox->text);
			tmp[(int)(in)] = entry;
		}
		tmp[(int)in + 1] = 0;
		if (textbox->text)
			free(textbox->text);
		textbox->text = ft_strdup(&tmp[0]);
	}
	else
	{
		out = ft_strjoin(textbox->text, ((char *)(&entry)));
		free(textbox->text);
		textbox->text = out;
	}
	return (textbox);
}

t_textbox	*textbox_clear(t_textbox *const textbox)
{
	if (textbox->text)
	{
		free(textbox->text);
		textbox->text = NULL;
	}
	return (textbox);
}
