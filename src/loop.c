/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 03:29:03 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/13 15:18:30 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"
#include "error.h"
#include "constants.h"
#include "debug.h"
#include "parameters.h"
#include "scene.h"
#include "input.h"
#include "gl_include.h"
#include "img_parsing.h"
#include "environment.h"

t_scene	*loop_start(t_context *const context, t_gui *const gui,
		t_scene *const scene, t_input *const input)
{
	Uint32		start_ticks;
	Uint32		tmp;
	static int	run = 1;

	while (run)
	{
		start_ticks = SDL_GetTicks();
		glClear(GL_COLOR_BUFFER_BIT);
		(context->render) ? context_draw(context, scene) : (void)42;
		gui_draw(gui);
		glFinish();
		gui->stats.drawtime = SDL_GetTicks() - start_ticks;
		tmp = SDL_GetTicks();
		run = input_scan(input, context, gui, &input->events);
		gui->stats.inputtime = SDL_GetTicks() - tmp;
		tmp = SDL_GetTicks();
		gui_frame_update(gui, scene);
		gui->stats.guitime = SDL_GetTicks() - tmp;
		tmp = SDL_GetTicks();
		input_handle(input, context, gui, scene);
		gui->stats.inputtime += SDL_GetTicks() - tmp;
		gui->stats.frametime = SDL_GetTicks() - start_ticks;
		gui->stats.fps = gui->stats.frametime ? 1000 / gui->stats.frametime : 1;
	}
	return (scene);
}
