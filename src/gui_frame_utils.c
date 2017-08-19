/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_frame_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 02:28:53 by jleu              #+#    #+#             */
/*   Updated: 2017/03/03 07:19:23 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "libft.h"
#include <stdlib.h>
#include "ft_str.h"
#include "constants.h"

static int	while_test(t_gui *const gui, t_ivec2 *const pos,
			void **const clicked)
{
	int			i;

	i = 0;
	while (i < gui->frame.n_panels &&
		!(panel_is_on(gui->frame.panels[i], pos)
		&& ((*clicked = textboxes_click(gui->frame.panels[i]->textboxes,
		gui->frame.panels[i]->n_textboxes, &gui->frame, pos)) ||
		(*clicked = buttons_click(gui->frame.panels[i]->buttons,
		gui->frame.panels[i]->n_buttons, &gui->frame, pos)) ||
		(*clicked = forms_click(gui->frame.panels[i]->forms,
		gui->frame.panels[i]->n_forms, &gui->frame, pos)) ||
		(*clicked = lockers_click(gui->frame.panels[i]->lockers,
		gui->frame.panels[i]->n_lockers, &gui->frame, pos)))))
		++i;
	return (i);
}

t_gui		*gui_frame_click(t_gui *const gui, t_ivec2 *const pos,
			void **const clicked)
{
	static void	*old_clicked = NULL;

	if (gui->frame.focused && gui->frame.focused_type == ET_RACK)
		old_clicked = gui->frame.focused;
	while_test(gui, pos, clicked);
	if (old_clicked && *clicked && gui->frame.focused_type == ET_RACK &&
		gui->frame.focused != old_clicked)
	{
		*(t_bool *)(old_clicked) = FALSE;
		old_clicked = NULL;
	}
	if (!*clicked)
	{
		gui->frame.focused = NULL;
		gui->frame.focused_type = ET_NONE;
	}
	return (gui);
}

t_gui		*gui_frame_unclick(t_gui *const gui, void **const clicked)
{
	if (clicked && *clicked)
	{
		if (gui->frame.focused_type != ET_RACK &&
			gui->frame.focused_type != ET_NONE)
			*(char *)(*clicked) = FALSE;
	}
	return (gui);
}
