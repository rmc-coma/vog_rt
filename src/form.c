/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 01:18:41 by jleu              #+#    #+#             */
/*   Updated: 2017/03/01 01:21:45 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "libft.h"

t_form	*form_build(t_form *const form, t_frame *const frame)
{
	int	i;
	int	max_i;
	int	j;
	int	max_j;

	if ((!form || (form->type == FT_LIST && (!form->locker ||
	!form->locker->active || form->target != form->locker->active->value_type)))
	|| (form->pos.x < 0 || form->pos.x
		> frame->width || form->pos.y < 0 || form->pos.y > frame->height ||
		form->pos.x + form->width > frame->width || form->pos.y + form->height
		> frame->height))
		return (form);
	i = form->pos.y;
	max_i = form->height + form->pos.y;
	max_j = form->width + form->pos.x;
	while (i < max_i)
	{
		j = form->pos.x - 1;
		while (++j < max_j)
			frame->gl_surface[j + i * frame->width] = form->bg_color;
		++i;
	}
	return (form);
}

t_form	*form_update(t_form *const form, t_gui *const gui)
{
	int	i;

	if (!form || (form->type == FT_LIST &&
		(!form->locker || !form->locker->active ||
		form->target != form->locker->active->value_type)))
		return (form);
	form_build(form, &gui->frame);
	i = 0;
	while (i < form->n_textboxes)
		textbox_update(form->textboxes[i++], gui);
	i = 0;
	while (i < form->n_buttons)
		button_update(form->buttons[i++], gui);
	return (form);
}

void	*forms_click(t_form *const *forms, const int n_forms,
			t_frame *const frame, t_ivec2 *const pos)
{
	int		i;
	void	*clicked;

	i = 0;
	while (i < n_forms)
	{
		if (form_is_on(forms[i], pos) &&
			((clicked = textboxes_click(forms[i]->textboxes,
			forms[i]->n_textboxes, frame, pos)) ||
			(clicked = buttons_click(forms[i]->buttons, forms[i]->n_buttons,
			frame, pos))))
			return (clicked);
		++i;
	}
	return (NULL);
}

t_bool	form_is_on(t_form *const form, t_ivec2 *const pos)
{
	return (pos->x >= form->pos.x &&
		pos->x <= form->pos.x + form->width &&
		pos->y >= form->pos.y &&
		pos->y <= form->pos.y + form->height ?
			TRUE : FALSE);
}
