/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 14:25:04 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/13 17:49:35 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "parameters.h"
#include "error.h"
#include "libft.h"
#include <stdio.h>

t_window		*window_init(t_window *const window)
{
	ft_bzero((void *)window, sizeof(t_window));
	window->width = WINDOW_WIDTH;
	window->height = WINDOW_HEIGHT;
	window->title = ft_strdup(WINDOW_TITLE);
	window->pos = ivec2(WINDOW_X_POS, WINDOW_Y_POS);
	window->flags = WINDOW_FLAGS;
	return (window);
}

void			window_vsync_switch(void)
{
	if (SDL_GL_GetSwapInterval() == 0)
		SDL_GL_SetSwapInterval(1);
	else
		SDL_GL_SetSwapInterval(0);
}

void			window_showcursor_switch(void)
{
	if (SDL_ShowCursor(SDL_QUERY) == SDL_DISABLE)
		SDL_ShowCursor(SDL_ENABLE);
	else
		SDL_ShowCursor(SDL_DISABLE);
}

static t_window	*window_create2(t_window *const window)
{
	SDL_GL_SetSwapInterval(VSYNC_ACTIVE);
	glGenTextures(1, &window->gui.gl_frametexture);
	glBindTexture(GL_TEXTURE_2D, window->gui.gl_frametexture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, window->context.width,
	window->context.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glBindTexture(GL_TEXTURE_2D, 0);
	glGenFramebuffers(1, &window->context.gl_framebuffer);
	glBindFramebuffer(GL_FRAMEBUFFER, window->context.gl_framebuffer);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D,
		window->gui.gl_frametexture, 0);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	return (window);
}

t_window		*window_create(t_window *const window)
{
	if (!window)
		return ((void *)0);
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		SDL_Quit();
		return ((void *)0);
	}
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
						SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 0);
	SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 0);
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 0);
	if (!(window->sdl_ptr = SDL_CreateWindow(window->title, window->pos.x,
		window->pos.y, window->width, window->height, window->flags)) ||
		!(window->context.gl_ptr = SDL_GL_CreateContext(window->sdl_ptr)))
	{
		SDL_Quit();
		return ((void *)0);
	}
	return (window_create2(window));
}
