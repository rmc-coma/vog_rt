/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textbox_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 23:19:22 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/08 18:25:51 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "ft_str.h"
#include "libft.h"

static void	*fetch_light_data(t_light *const light, const t_tdata_type tdt)
{
	if (tdt >= TDT_TRANSFORM_PX && tdt <= TDT_TRANSFORM_PZ)
		return (&(((float *)(&light->pos))[(int)tdt - TDT_TRANSFORM_PX]));
	if (tdt >= TDT_LIGHT_INTENSITY && tdt <= TDT_LIGHT_AMBIANT)
		return (&(((float *)(&light->intensity))[(int)tdt -
				TDT_LIGHT_INTENSITY]));
	else if (tdt >= TDT_LIGHT_DIR_X && tdt <= TDT_LIGHT_DIR_Z)
		return (&(((float *)(&light->dir))[(int)tdt - TDT_LIGHT_DIR_X]));
	else if (tdt >= TDT_COLOR_R && tdt <= TDT_COLOR_B)
		return (&(((float *)(&light->color))[(int)tdt - TDT_COLOR_R]));
	return (NULL);
}

static void	*fetch_camera_data(t_camera *const camera, const t_tdata_type tdt)
{
	if (tdt >= TDT_TRANSFORM_PX && tdt <= TDT_TRANSFORM_PZ)
		return (&(((float *)(&camera->pos))[(int)tdt - TDT_TRANSFORM_PX]));
	else if (tdt >= TDT_TRANSFORM_RX && tdt <= TDT_TRANSFORM_RZ)
		return (&(((float *)(&camera->dir))[(int)tdt - TDT_TRANSFORM_RX]));
	else if (tdt == TDT_CAMERA_FOV)
		return (&camera->fov);
	else if (tdt == TDT_CAMERA_PHI)
		return (&camera->phi);
	else if (tdt == TDT_CAMERA_THETA)
		return (&camera->theta);
	return (NULL);
}

static void	*fetch_object_data(t_object *const object, const t_tdata_type tdt)
{
	if (tdt >= TDT_TRANSFORM_PX && tdt <= TDT_TRANSFORM_SZ)
		return (&(((float *)(object->transform))[(int)tdt - TDT_TRANSFORM_PX]));
	else if (tdt >= TDT_COLOR_R && tdt <= TDT_COLOR_B)
		return (&(((float *)(&object->mesh->material->color))
				[(int)(tdt - TDT_COLOR_R)]));
	else if (tdt >= TDT_MAT_AMBIANT && tdt <= TDT_MAT_ROUGH)
	{
		return (&(((float *)(&object->mesh->material->ambiant))
				[(int)tdt - TDT_MAT_AMBIANT]));
	}
	return (NULL);
}

static void	*fetch_data(void *const rv, const t_rvalue_type rvt,
				t_textbox *const textbox, const t_tdata_type tdt)
{
	if (rvt == RVT_CAMERA && textbox->parent->target == RVT_CAMERA)
		return (fetch_camera_data((t_camera *)rv, tdt));
	else if (rvt == RVT_LIGHT && textbox->parent->target == RVT_LIGHT)
		return (fetch_light_data((t_light *)rv, tdt));
	else if (rvt == RVT_OBJECT && textbox->parent->target == RVT_OBJECT)
		return (fetch_object_data((t_object *)rv, tdt));
	return (NULL);
}

t_textbox	*textbox_data_fetch(t_textbox *const textbox, t_gui *const gui)
{
	(void)gui;
	textbox->data = fetch_data(textbox->parent->locker->active->value->id,
		textbox->parent->locker->active->value_type, textbox,
		textbox->data_type);
	textbox->fetched = textbox->parent->locker->active;
	return (textbox);
}
