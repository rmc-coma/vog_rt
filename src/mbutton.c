/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbutton.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 01:55:57 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/03 07:30:59 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

t_mbutton	mbutton(const int is_down, const Uint32 press_timestamp,
				const t_ivec2 press_coords)
{
	t_mbutton	new;

	new.is_down = is_down;
	new.press_timestamp = press_timestamp;
	new.press_coords = press_coords;
	new.handle_timestamp = 0;
	return (new);
}

t_mbutton	*mbutton_press(t_mbutton *const mbutton, t_gui *const gui,
				t_input *const input, void **const clicked)
{
	if (mbutton->is_down && !mbutton->handle_timestamp && !input->writing)
	{
		gui_frame_click(gui, &mbutton->press_coords, clicked);
		mbutton->handle_timestamp = SDL_GetTicks();
		if (gui->frame.focused_type == ET_TEXTBOX && ((t_textbox *)
			(gui->frame.focused))->editable)
			input->writing = TRUE;
	}
	return (mbutton);
}

t_mbutton	*mbutton_unpress(t_mbutton *const mbutton, t_gui *const gui,
				void **const clicked)
{
	gui_frame_unclick(gui, clicked);
	mbutton->is_down = FALSE;
	mbutton->press_timestamp = 0;
	mbutton->press_coords = ivec2(0, 0);
	mbutton->handle_timestamp = 0;
	return (mbutton);
}
