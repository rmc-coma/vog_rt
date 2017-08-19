/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 23:47:35 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/01 03:20:19 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "ft_str.h"

t_gui	*gui_write(t_gui *const g, const char *const s, const GLuint c,
		const t_ivec2 *p)
{
	int	i;
	int	j;
	int	k;

	if ((p->x >= g->frame.width && p->y >= g->frame.height) ||
		(p->x + g->fontdata.letter_width * ft_strlen(s) >=
		(unsigned long)g->frame.width || p->y + g->fontdata.height
		>= g->frame.height))
		return (g);
	i = -1;
	while (s[++i])
	{
		j = -1;
		while (++j < g->fontdata.letter_width)
		{
			k = -1;
			while (++k < g->fontdata.height)
				g->frame.gl_surface[p->x + j + i * g->fontdata.letter_width +
				(p->y + k) * g->frame.width] = g->font[((s[i] - 32) *
				g->fontdata.letter_width + j) + k * g->fontdata.width] ? c :
				g->frame.gl_surface[p->x + j + i * g->fontdata.letter_width +
				(p->y + k) * g->frame.width];
		}
	}
	return (g);
}

t_gui	*gui_clrline(t_gui *const gui, const t_ivec2 *pos)
{
	int	i;
	int	j;

	i = -1;
	while (++i < gui->frame.width)
	{
		j = -1;
		while (++j < gui->fontdata.height)
			gui->frame.gl_surface[pos->x + i + (pos->y + j) *
			gui->frame.width] = 0;
	}
	return (gui);
}

t_gui	*gui_line_update(t_gui *const gui, const t_ivec2 *pos)
{
	glBindBuffer(GL_TEXTURE_BUFFER, gui->frame.gl_id);
	glBufferSubData(GL_TEXTURE_BUFFER,
		(pos->x + pos->y * gui->frame.width) << 2,
		(gui->frame.width - 1 + (pos->y + gui->fontdata.height) *
		gui->frame.width) << 2,
		(GLvoid *)&gui->frame.gl_surface[pos->x + pos->y * gui->frame.width]);
	glBindBuffer(GL_TEXTURE_BUFFER, 0);
	return (gui);
}
