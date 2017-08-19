/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_frame_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 05:37:44 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/08 18:25:53 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "libft.h"
#include <stdlib.h>
#include "ft_str.h"
#include "input.h"
#include "constants.h"

static void	update_data2(t_textbox *const focused)
{
	if (focused->data_type >= TDT_COLOR_R &&
			focused->data_type <= TDT_COLOR_B)
	{
		if (*(float *)focused->data > 1.0f)
			*(float *)focused->data = 1.0f;
		else if (*(float *)focused->data < 0.0f)
			*(float *)focused->data = 0.0f;
		ubuffernode_subdata(focused->fetched->value->children_nodes
			[CONST_OBJECT_MESH_SLOT]->children_nodes
			[CONST_MESH_MATERIAL_SLOT]);
	}
	else if (focused->data_type >= TDT_MAT_AMBIANT &&
			focused->data_type <= TDT_MAT_ROUGH)
	{
		ubuffernode_subdata(focused->fetched->value->children_nodes
			[CONST_OBJECT_MESH_SLOT]->children_nodes
			[CONST_MESH_MATERIAL_SLOT]);
	}
}

static void	update_data(t_textbox *const focused)
{
	if (focused->fetched->value_type == RVT_CAMERA)
		ubuffernode_subdata(focused->fetched->value);
	else if (focused->fetched->value_type == RVT_OBJECT)
	{
		if (focused->data_type >= TDT_TRANSFORM_PX &&
			focused->data_type <= TDT_TRANSFORM_SZ)
		{
			transform_update_quaternion((t_transform *)
				(focused->fetched->value->children_nodes
				[CONST_OBJECT_TRANSFORM_SLOT]->id));
			ubuffernode_subdata(focused->fetched->value->children_nodes
				[CONST_OBJECT_TRANSFORM_SLOT]);
		}
		else
			update_data2(focused);
	}
	else if (focused->fetched->value_type == RVT_LIGHT)
	{
		if (focused->data_type >= TDT_LIGHT_INTENSITY &&
			focused->data_type <= TDT_LIGHT_AMBIANT)
			ubuffernode_subdata(focused->fetched->value);
		else if (focused->data_type >= TDT_TRANSFORM_PX &&
				focused->data_type <= TDT_TRANSFORM_PZ)
			ubuffernode_subdata(focused->fetched->value);
	}
}

t_gui		*gui_frame_endwrite(t_gui *const gui)
{
	t_textbox	*focused;

	if (gui->frame.focused_type == ET_TEXTBOX &&
		((t_textbox *)(gui->frame.focused))->editable)
	{
		focused = ((t_textbox *)(gui->frame.focused));
		if (focused->type == TT_DATA)
		{
			*(float *)(focused->data) = ft_atof(focused->text);
			update_data(focused);
		}
	}
	gui->frame.focused = NULL;
	gui->frame.focused_type = ET_NONE;
	return (gui);
}

t_gui		*gui_frame_write(t_gui *const gui, const char entry)
{
	textbox_append(((t_textbox *)(gui->frame.focused)), entry);
	return (gui);
}

t_gui		*gui_frame_backwrite(t_gui *const gui)
{
	char	*tmp;
	int		len;

	if (gui->frame.focused_type == ET_TEXTBOX && ((t_textbox *)
		(gui->frame.focused))->editable)
	{
		len = ft_strlen(((t_textbox *)(gui->frame.focused))->text);
		if (!len)
			return (gui);
		tmp = (char *)ft_memalloc(len);
		ft_memcpy(tmp, ((t_textbox *)(gui->frame.focused))->text, len - 1);
		tmp[len - 1] = 0;
		free(((t_textbox *)(gui->frame.focused))->text);
		((t_textbox *)(gui->frame.focused))->text = tmp;
	}
	return (gui);
}
