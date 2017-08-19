/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 05:48:52 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/02 03:22:43 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context.h"
#include "gui.h"
#include "scene.h"

#include <stdio.h>

t_context	*context_draw(t_context *const context, t_scene *const scene)
{
	glBindFramebuffer(GL_FRAMEBUFFER, context->gl_framebuffer);
	glViewport(0, 0, context->width, context->height);
	glUseProgram(context->gpu_program.gl_id);
	glBindVertexArray(context->vao_id);
	scene_bind_ubuffers(scene, context);
	glUniform1iv(scene->current_cam_loc, 1, &scene->current_cam_index);
	glUniform1fv(context->ratio_location, 1, &context->ratio);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);
	glDisableVertexAttribArray(0);
	glUseProgram(0);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	context->render = FALSE;
	return (context);
}

t_context	*context_render_switch(t_context *const context)
{
	context->render = !context->render;
	return (context);
}

char		context_is_on(t_context *const context, t_ivec2 *const pos)
{
	return (pos->x >= context->pos.x && pos->x <=
			(context->pos.x + context->width) &&
			pos->y >= context->pos.y && pos->y <=
			(context->pos.y + context->height) ?
			TRUE : FALSE);
}
