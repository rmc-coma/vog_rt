/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 02:48:53 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/01 04:53:28 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "ft_str.h"

t_locker	*locker_build(t_locker *const locker, t_frame *const frame)
{
	int	i;
	int	max_i;
	int	j;
	int	max_j;

	i = locker->pos.y;
	max_i = locker->height + locker->pos.y;
	max_j = locker->width + locker->pos.x;
	while (i < max_i)
	{
		j = locker->pos.x;
		while (j < max_j)
		{
			frame->gl_surface[j + i * frame->width] = locker->bg_color;
			++j;
		}
		++i;
	}
	return (locker);
}

t_locker	*locker_update(t_locker *const locker, t_scene *const scene,
				t_gui *const gui)
{
	t_ivec2		pos;
	t_rack		*rack;

	locker_build(locker, &gui->frame);
	if (!locker->n_racks)
	{
		locker_fill(locker, scene, gui);
		locker_forms_link(locker, &gui->frame);
	}
	else if (locker->n_racks != racks_count(locker->racks))
	{
		locker_empty(locker);
		locker_fill(locker, scene, gui);
		locker_forms_link(locker, &gui->frame);
	}
	pos = ivec2(locker->pos.x + locker->padding,
		locker->pos.y + locker->padding * locker->width / locker->height);
	gui_putstr(gui, locker->text, &locker->color, &pos);
	rack = locker->racks;
	while (rack)
	{
		rack_update(rack, gui);
		rack = rack->next;
	}
	return (locker);
}

void		*lockers_click(t_locker *const *lockers, const int n_lockers,
				t_frame *const frame, t_ivec2 *const pos)
{
	int			i;
	void		*clicked;

	i = 0;
	while (i < n_lockers)
	{
		if (locker_is_on(lockers[i], pos))
		{
			if ((clicked = racks_click(lockers[i]->racks,
							lockers[i]->n_racks, frame, pos)))
			{
				frame->focused = clicked;
				frame->focused_type = ET_RACK;
				lockers[i]->active = clicked;
				return (clicked);
			}
			lockers[i]->active = NULL;
			frame->focused = (void *)lockers[i];
			frame->focused_type = ET_LOCKER;
			return (lockers[i]);
		}
		++i;
	}
	return (NULL);
}

t_bool		locker_is_on(t_locker *const locker, t_ivec2 *const pos)
{
	return (pos->x >= locker->pos.x &&
		pos->x <= locker->pos.x + locker->width &&
		pos->y >= locker->pos.y &&
		pos->y <= locker->pos.y + locker->height ?
		TRUE : FALSE);
}
