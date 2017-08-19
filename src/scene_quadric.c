/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_quadric.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 03:34:24 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/02/27 22:33:19 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "constants.h"
#include "shad_struct.h"
#include "context.h"

t_scene		*scene_init_quadrics(t_scene *scene, t_context *context)
{
	ubufferlist_init(&scene->quadrics, shad_struct_get(SHAD_QUADRIC), context);
	return (scene);
}
