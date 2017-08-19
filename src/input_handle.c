/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 03:57:22 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/03 06:53:12 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "constants.h"

t_input		*input_handle_mouse(t_input *const input, t_scene *const scene,
								t_gui *const gui)
{
	static void	*clicked = NULL;

	if (input->mbuttons[0].is_down && !input->mbuttons[0].handle_timestamp)
		mbutton_press(&input->mbuttons[0], gui, input, &clicked);
	else if (!input->mbuttons[0].is_down && input->mbuttons[0].handle_timestamp)
		mbutton_unpress(&input->mbuttons[0], gui, &clicked);
	if (clicked)
		scene_change_current(scene, input, gui, clicked);
	return (input);
}

t_input		*input_handle_key(t_input *const input, t_scene *const scene,
				t_context *const context, t_gui *const gui)
{
	int		i;

	i = 0;
	while (i < input->n_keys)
	{
		if (input->keys[i]->is_down && input->keys[i]->func != NULL)
		{
			if (input->keys[i]->type == KT_NONE)
				input->keys[i]->func(0, 0, 0);
			else if (input->keys[i]->type == KT_LIVE)
			{
				context->render = TRUE;
				input->keys[i]->func(scene->current_obj->id,
								gui->stats.frametime,
								scene->current_cam->id);
				ubuffernode_subdata(scene->current_obj);
			}
			else if (input->keys[i]->type == KT_SWITCH)
				if (input->keys[i]->handle_timestamp == 0)
					input->keys[i]->func(context, 0, 0);
			input->keys[i]->handle_timestamp = SDL_GetTicks();
		}
		++i;
	}
	return (input);
}

t_input		*input_handle(t_input *const input, t_context *const context,
				t_gui *const gui, t_scene *const scene)
{
	input_handle_key(input, scene, context, gui);
	input_handle_mouse(input, scene, gui);
	return (input);
}
