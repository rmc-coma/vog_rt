/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 00:57:20 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/01 22:59:06 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "libft.h"
#include <stdio.h>

t_button	*button_build(t_button *const button, t_frame *const frame)
{
	GLuint	color;
	int		i;
	int		max_i;
	int		j;
	int		max_j;

	color = button->clicked ? (button->bg_color & 0xFF000000)
			| ~button->bg_color : button->bg_color;
	i = button->pos.y;
	max_i = button->height + button->pos.y;
	max_j = button->width + button->pos.x;
	while (i < max_i)
	{
		j = button->pos.x;
		while (j < max_j)
		{
			frame->gl_surface[j + i * frame->width] = color;
			++j;
		}
		++i;
	}
	return (button);
}

t_button	*button_update(t_button *const button, t_gui *const gui)
{
	t_ivec2	pos;
	GLuint	color;

	button_build(button, &gui->frame);
	pos = ivec2(button->pos.x + ((button->width - ft_strlen(button->text) *
		gui->fontdata.letter_width) >> 1), button->pos.y +
		(button->height >> 1) - (gui->fontdata.height >> 1));
	color = (button->color & 0xFF000000) | ~button->color;
	gui_putstr(gui, button->text, button->clicked ? &color :
		&button->color, &pos);
	return (button);
}

t_button	*buttons_click(t_button *const *buttons, const int n_buttons,
				t_frame *const frame, t_ivec2 *const pos)
{
	int		i;

	i = 0;
	while (i < n_buttons)
	{
		if (button_is_on(buttons[i], pos))
		{
			buttons[i]->clicked = TRUE;
			buttons[i]->click_timestamp = SDL_GetTicks();
			buttons[i]->click_func(NULL, NULL, NULL, NULL);
			frame->focused = (void *)buttons[i];
			frame->focused_type = ET_BUTTON;
			return (buttons[i]);
		}
		++i;
	}
	return (NULL);
}

t_bool		button_is_on(t_button *const button, t_ivec2 *const pos)
{
	return (pos->x >= button->pos.x &&
		pos->x <= button->pos.x + button->width &&
		pos->y >= button->pos.y &&
		pos->y <= button->pos.y + button->height ?
		TRUE : FALSE);
}
