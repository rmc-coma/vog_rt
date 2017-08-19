/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 03:56:47 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/08 17:02:47 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

#include <stdio.h>

t_panel	*panel_build(t_panel *const panel, t_frame *const frame)
{
	int		i;
	int		max_i;
	int		j;
	int		max_j;

	i = panel->pos.y;
	max_i = panel->pos.y + panel->height;
	max_j = panel->pos.x + panel->width;
	while (i < max_i)
	{
		j = panel->pos.x;
		while (j < max_j)
		{
			frame->gl_surface[j + i * frame->width] = panel->bg_color;
			++j;
		}
		++i;
	}
	return (panel);
}

t_panel	*panel_update(t_panel *const panel, t_gui *const gui,
					t_scene *const scene)
{
	int		i;

	panel_build(panel, &gui->frame);
	i = 0;
	while (i < panel->n_lockers)
		locker_update(panel->lockers[i++], scene, gui);
	i = 0;
	while (i < panel->n_forms)
		form_update(panel->forms[i++], gui);
	i = 0;
	while (i < panel->n_textboxes)
		textbox_update(panel->textboxes[i++], gui);
	i = 0;
	while (i < panel->n_buttons)
		button_update(panel->buttons[i++], gui);
	return (panel);
}

t_bool	panel_is_on(t_panel *const panel, t_ivec2 *const pos)
{
	return (pos->x >= panel->pos.x && pos->x <= (panel->pos.x + panel->width) &&
		pos->y >= panel->pos.y && pos->y <= (panel->pos.y + panel->height) ?
		TRUE : FALSE);
}
