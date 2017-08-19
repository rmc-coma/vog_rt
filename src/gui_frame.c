/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_frame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 01:12:03 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/01 01:31:18 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "libft.h"
#include <stdlib.h>

t_gui	*gui_frame_update(t_gui *const gui, t_scene *const scene)
{
	int		i;

	i = 0;
	while (i < gui->frame.n_panels)
		panel_update(gui->frame.panels[i++], gui, scene);
	glBindBuffer(GL_TEXTURE_BUFFER, gui->frame.gl_id);
	glBufferData(GL_TEXTURE_BUFFER, gui->frame.gl_surface_size,
			(GLvoid *)gui->frame.gl_surface, GL_DYNAMIC_DRAW);
	glBindBuffer(GL_TEXTURE_BUFFER, 0);
	return (gui);
}
