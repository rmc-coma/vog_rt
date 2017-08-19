/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 17:24:43 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/02/28 04:02:22 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "error.h"
#include "object.h"
#include "camera.h"
#include "debug.h"
#include "context.h"
#include "gui.h"
#include "input.h"
#include "constants.h"

t_scene		*scene_change_current(t_scene *const scene, t_input *const input,
				t_gui *const gui, void *const clicked)
{
	if (gui->frame.focused_type == ET_RACK)
	{
		if (((t_rack *)clicked)->value_type == RVT_CAMERA)
		{
			input->keys = keys_switch_type_cam(input->keys);
			scene->current_obj = ((t_rack *)clicked)->value;
		}
		else if (((t_rack *)clicked)->value_type == RVT_OBJECT)
		{
			input->keys = keys_switch_type_obj(input->keys);
			scene->current_obj = ((t_rack *)clicked)->value->children_nodes
				[CONST_OBJECT_TRANSFORM_SLOT];
		}
		else if (((t_rack *)clicked)->value_type == RVT_LIGHT)
		{
			input->keys = keys_switch_type_lit(input->keys);
			scene->current_obj = ((t_rack *)clicked)->value;
		}
	}
	return (scene);
}

t_scene		*scene_init(t_scene *scene, t_context *context)
{
	scene->current_cam_index = 0;
	scene->current_obj = (t_ubuffernode *)0;
	scene->current_cam = (t_ubuffernode *)0;
	glUseProgram(context->gpu_program.gl_id);
	glBindVertexArray(context->vao_id);
	scene->current_cam_loc = glGetUniformLocation(context->gpu_program.gl_id,
		"current_camera");
	glBindVertexArray(0);
	glUseProgram(0);
	scene_init_cameras(scene, context);
	scene_init_objects(scene, context);
	scene_init_transforms(scene, context);
	scene_init_lights(scene, context);
	scene_init_meshes(scene, context);
	scene_init_geometries(scene, context);
	scene_init_planes(scene, context);
	scene_init_materials(scene, context);
	scene_init_tori(scene, context);
	scene_init_boxes(scene, context);
	scene_init_mobius(scene, context);
	scene_init_quadrics(scene, context);
	scene_init_cubics(scene, context);
	return (scene);
}

t_scene		*scene_bind_ubuffers(t_scene *scene, t_context *context)
{
	GLuint	program_id;

	program_id = context->gpu_program.gl_id;
	glUniform1iv(scene->current_cam_loc, 1, &scene->current_cam_index);
	ubufferlist_bind_data(&scene->cameras, program_id);
	ubufferlist_bind_data(&scene->objects, program_id);
	ubufferlist_bind_data(&scene->transforms, program_id);
	ubufferlist_bind_data(&scene->lights, program_id);
	ubufferlist_bind_data(&scene->meshes, program_id);
	ubufferlist_bind_data(&scene->geometries, program_id);
	ubufferlist_bind_data(&scene->planes, program_id);
	ubufferlist_bind_data(&scene->materials, program_id);
	ubufferlist_bind_data(&scene->tori, program_id);
	ubufferlist_bind_data(&scene->boxes, program_id);
	ubufferlist_bind_data(&scene->mobius, program_id);
	ubufferlist_bind_data(&scene->quadrics, program_id);
	ubufferlist_bind_data(&scene->cubics, program_id);
	return (scene);
}
