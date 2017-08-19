/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 04:17:40 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/03 06:37:41 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "libft.h"
#include "ft_str.h"
#include <stdio.h>

t_textbox			*textbox_build(t_textbox *const textbox,
					t_frame *const frame)
{
	int			i;
	int			max_i;
	int			j;
	int			max_j;

	if ((textbox->parent && (textbox->pos.x < textbox->parent->pos.x ||
		textbox->pos.x + textbox->width >= textbox->parent->pos.x +
		textbox->parent->width || textbox->pos.y < textbox->parent->pos.y ||
		textbox->pos.y + textbox->height >= textbox->parent->pos.y +
		textbox->parent->height)) || (textbox->pos.x < 0 || textbox->pos.x +
		textbox->width >= frame->width || textbox->pos.y < 0 ||
		textbox->pos.y + textbox->height >= frame->height))
		return (textbox);
	i = textbox->pos.y;
	max_i = textbox->height + textbox->pos.y;
	max_j = textbox->width + textbox->pos.x;
	while (i < max_i)
	{
		j = textbox->pos.x;
		while (j < max_j)
			frame->gl_surface[j++ + i * frame->width] = textbox->bg_color;
		++i;
	}
	return (textbox);
}

static t_textbox	*textbox_update2(t_textbox *const t, t_gui *const gui,
					char tmp[32], t_ivec2 *pos)
{
	if (gui->frame.focused != t)
	{
		textbox_data_fetch(t, gui);
		if (!t->data || t->data_type == TDT_NONE)
			return (t);
		if (t->text)
			free(t->text);
		ft_ftoal(*(float *)t->data, &tmp[0]);
		t->text = ft_strdup(&tmp[0]);
	}
	gui_putstr(gui, t->text, &t->color, pos);
	return (t);
}

t_textbox			*textbox_update(t_textbox *const t, t_gui *const gui)
{
	t_ivec2			pos;
	char			tmp[32];

	textbox_build(t, &gui->frame);
	pos = ivec2(t->pos.x + t->padding, t->pos.y + (t->height >> 1)
			- (gui->fontdata.height >> 1));
	if (t->type == TT_DATA && t->parent && t->parent->locker
		&& t->parent->locker->active)
		textbox_update2(t, gui, tmp, &pos);
	else if (t->type != TT_DATA)
	{
		if (t->text)
			ft_memcpy(&tmp[0], t->text, ft_strlen(t->text));
		tmp[ft_strlen(t->text)] = 0;
		if (t->type != TT_TEXT)
			ft_itoal(((int *)(&gui->stats))[t->type - TT_FRAMETIME],
					&tmp[ft_strlen(t->text)]);
		gui_putstr(gui, &tmp[0], &t->color, &pos);
	}
	if (t->editable && gui->frame.focused == t)
	{
		pos.x += t->text ? ft_strlen(t->text) * gui->fontdata.letter_width : 0;
		gui_putstr(gui, "_", &t->color, &pos);
	}
	return (t);
}

t_textbox			*textboxes_click(t_textbox *const *textboxes,
					const int n_textboxes, t_frame *const frame,
					t_ivec2 *const pos)
{
	int		i;

	i = 0;
	while (i < n_textboxes)
	{
		if (textbox_is_on(textboxes[i], pos) && textboxes[i]->data)
		{
			frame->focused = (void *)textboxes[i];
			frame->focused_type = ET_TEXTBOX;
			return (textboxes[i]);
		}
		++i;
	}
	return (NULL);
}

t_bool				textbox_is_on(t_textbox *const textbox, t_ivec2 *const pos)
{
	return (pos->x >= textbox->pos.x &&
		pos->x <= textbox->pos.x + textbox->width &&
		pos->y >= textbox->pos.y &&
		pos->y <= textbox->pos.y + textbox->height ?
		TRUE : FALSE);
}
