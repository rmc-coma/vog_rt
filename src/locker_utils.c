/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locker_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 06:25:36 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/02 02:05:06 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "ft_str.h"
#include "constants.h"

t_locker		*locker_empty(t_locker *const locker)
{
	t_rack			*rack;
	t_rack			*to_free;

	rack = locker->racks;
	while (rack)
	{
		to_free = rack;
		rack = rack->next;
		free(to_free->text);
		free(to_free);
	}
	locker->racks = NULL;
	locker->n_racks = 0;
	return (locker);
}

static void		locker_fill_from_prep(char *const str, t_ubuffernode **list,
					t_ubufferlist *source, int *i)
{
	str[0] = 32;
	*list = source->first_node;
	ft_strcpy(&str[16], source->gl_name);
	str[ft_strlen(source->gl_name) + 15] = 0;
	*i = -1;
}

static t_locker	*locker_fill_from(t_locker *const locker, t_scene *const scene,
								t_ubufferlist *const source)
{
	char			str[32];
	t_ubuffernode	*list;
	int				i;
	t_rack			*rack;

	locker_fill_from_prep(&str[0], &list, source, &i);
	while (++i < source->n_nodes)
	{
		(!locker->racks) ? (locker->racks = rack_init(rack_new())) :
			(rack->next = rack_init(rack_new()));
		rack = locker->racks->next ? rack->next : locker->racks;
		rack->parent = locker;
		(source->gl_base == 1) ? rack->text = (ft_strjoin(geometry_name(
			(t_geometry *)(list->children_nodes[CONST_OBJECT_MESH_SLOT]
			->children_nodes[CONST_MESH_GEOMETRY_SLOT]->id)),
			ft_itoal(list->index, &str[1]) - 1)) : (rack->text =
			ft_strjoin(&str[16], ft_itoal(list->index, &str[1]) - 1));
		rack->pos.x = locker->pos.x;
		rack->pos.y = locker->pos.y + (++locker->n_racks) * locker->rack_height;
		rack->value = list;
		rack->value_type = (unsigned int)(source - (t_ubufferlist *)(scene));
		list = list->next;
	}
	return (locker);
}

t_locker		*locker_fill(t_locker *const locker, t_scene *const scene,
					t_gui *const gui)
{
	locker->rack_height = gui->fontdata.height + (locker->padding >> 1);
	locker_fill_from(locker, scene, &scene->cameras);
	locker_fill_from(locker, scene, &scene->objects);
	locker_fill_from(locker, scene, &scene->lights);
	return (locker);
}

t_locker		*locker_forms_link(t_locker *const locker, t_frame *const frame)
{
	int				i;
	int				j;

	i = 0;
	while (i < frame->n_panels)
	{
		j = 0;
		while (j < frame->panels[i]->n_forms)
		{
			if (frame->panels[i]->forms[j]->type == FT_LIST)
			{
				locker->form = frame->panels[i]->forms[j];
				frame->panels[i]->forms[j]->locker = locker;
			}
			++j;
		}
		++i;
	}
	return (locker);
}
