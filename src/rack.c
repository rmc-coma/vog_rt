/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rack.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 05:14:21 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/01 08:47:09 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

t_rack	*rack_build(t_rack *const rack, t_frame *const frame)
{
	GLuint	color;
	int		i;
	int		max_i;
	int		j;
	int		max_j;

	if (rack->pos.x < 0 || rack->pos.x > frame->width || rack->pos.y < 0 ||
		rack->pos.y > frame->height
		|| rack->pos.x + rack->parent->width > frame->width || rack->pos.y +
		rack->parent->rack_height > frame->height)
		return (rack);
	color = rack->clicked ? (rack->parent->bg_color & 0xFF000000) |
		~rack->parent->bg_color : rack->parent->bg_color;
	i = rack->pos.y - 1;
	max_i = rack->parent->rack_height + rack->pos.y;
	max_j = rack->parent->width + rack->pos.x;
	while (++i < max_i)
	{
		j = rack->pos.x - 1;
		while (++j < max_j)
			frame->gl_surface[j + i * frame->width] = color;
	}
	return (rack);
}

t_rack	*rack_update(t_rack *const rack, t_gui *const gui)
{
	GLuint	color;
	t_ivec2	pos;

	rack_build(rack, &gui->frame);
	color = rack->clicked ? ~rack->parent->color : rack->parent->color;
	pos = ivec2(rack->pos.x + rack->parent->padding + (rack->parent->padding *
		rack->parent->width / rack->parent->height), rack->pos.y -
		(gui->fontdata.height >> 1) + (rack->parent->rack_height >> 1));
	if (rack->pos.x <= rack->parent->pos.x + rack->parent->width &&
		rack->pos.y <= rack->parent->pos.y + rack->parent->height &&
		rack->text && rack->parent)
		gui_putstr(gui, rack->text, &color, &pos);
	return (rack);
}

t_rack	*racks_click(t_rack *racks, const int n_racks,
		t_frame *const frame, t_ivec2 *const pos)
{
	int		i;

	i = 0;
	while (i < n_racks)
	{
		if (rack_is_on(racks, pos))
		{
			frame->focused = (void *)racks;
			frame->focused_type = ET_RACK;
			racks->parent->active = racks;
			racks->clicked = 1;
			return (racks);
		}
		racks = racks->next;
		++i;
	}
	return (NULL);
}

t_bool	rack_is_on(t_rack *const rack, t_ivec2 *const pos)
{
	return (pos->x >= rack->pos.x &&
		pos->x <= rack->pos.x + rack->parent->width &&
		pos->y >= rack->pos.y &&
		pos->y <= rack->pos.y + rack->parent->rack_height ?
		TRUE : FALSE);
}

int		racks_count(t_rack *racks)
{
	int		i;

	i = 0;
	while (racks)
	{
		racks = racks->next;
		++i;
	}
	return (i);
}
