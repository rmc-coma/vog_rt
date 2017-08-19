/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 23:10:05 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/03 07:32:54 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "parameters.h"
#include "ubuffer.h"
#include "libft.h"
#include "gl_include.h"
#include "constants.h"

t_input	*input_set_keys_state(t_input *const input, SDL_Event *const events)
{
	int		i;

	i = -1;
	while (++i < input->n_keys)
		if (events->key.keysym.scancode == input->keys[i]->scancode)
		{
			input->keys[i]->is_down = (events->type == SDL_KEYDOWN);
			if (input->keys[i]->is_down)
			{
				input->keys[i]->press_timestamp = events->key.timestamp;
				input->keys[i]->handle_timestamp = 0;
			}
			else
				input->keys[i]->press_timestamp = 0;
		}
	if (events->type == SDL_MOUSEBUTTONDOWN && (events->button.button ==
		SDL_BUTTON_LEFT || events->button.button == SDL_BUTTON_RIGHT))
		input->mbuttons[events->button.button == 1 ? 0 : 1] = mbutton(TRUE,
			events->button.timestamp,
			ivec2(events->button.x, events->button.y));
	else if (events->type == SDL_MOUSEBUTTONUP && (events->button.button ==
		SDL_BUTTON_LEFT || events->button.button == SDL_BUTTON_RIGHT))
		input->mbuttons[events->button.button == 1 ? 0 : 1].is_down = FALSE;
	return (input);
}

int		input_scan_write(t_input *const input, t_context *const context,
			t_gui *const gui, SDL_Event *const events)
{
	if (events->key.keysym.scancode == SDL_SCANCODE_RETURN ||
		events->key.keysym.scancode == 88)
	{
		gui_frame_endwrite(gui);
		input->writing = FALSE;
		context->render = TRUE;
		input->mbuttons[0].is_down = FALSE;
	}
	else if (events->key.keysym.scancode == SDL_SCANCODE_BACKSPACE)
		gui_frame_backwrite(gui);
	else if (events->key.keysym.scancode == SDL_SCANCODE_SPACE)
		gui_frame_write(gui, ' ');
	else
	{
		if ((int)events->key.keysym.scancode >= 89 &&
			(int)events->key.keysym.scancode <= 98)
			events->key.keysym.scancode -= 59;
		else if ((int)events->key.keysym.scancode == 99)
			events->key.keysym.scancode -= 44;
		input->entry = (char *)SDL_GetScancodeName(events->key.keysym.scancode);
		gui_frame_write(gui, *input->entry);
	}
	return (1);
}

int		input_scan(t_input *const input, t_context *const context,
		t_gui *const gui, SDL_Event *const events)
{
	while (SDL_PollEvent(events))
	{
		if (events->type == SDL_QUIT ||
			events->key.keysym.scancode == SDL_SCANCODE_ESCAPE)
			return (0);
		if (input->writing && events->type == SDL_KEYDOWN)
			return (input_scan_write(input, context, gui, events));
		if (events->key.repeat == 0)
			input_set_keys_state(input, events);
	}
	return (1);
}
