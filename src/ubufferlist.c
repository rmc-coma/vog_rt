/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ubufferlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 21:27:55 by jleu              #+#    #+#             */
/*   Updated: 2017/02/28 21:31:37 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ubuffer.h"
#include "context.h"

t_ubufferlist	*ubufferlist_init(t_ubufferlist *list,
		t_shad_struct const *shad_struct, t_context const *context)
{
	list->gl_base = shad_struct->base;
	list->gl_name = shad_struct->varname;
	list->gl_n_name = shad_struct->n_varname;
	list->n_nodes = 0;
	list->first_node = NULL_NODE;
	datamodel_init(&list->datamodel, shad_struct);
	glGenBuffers(1, &list->gl_id);
	glBindBuffer(GL_UNIFORM_BUFFER, list->gl_id);
	glBufferData(GL_UNIFORM_BUFFER, context->hardware.uniform_buffer_size,
				(GLvoid *)0, GL_DYNAMIC_DRAW);
	glBindBuffer(GL_UNIFORM_BUFFER, 0);
	glBindVertexArray(context->vao_id);
	glBindBufferBase(GL_UNIFORM_BUFFER, list->gl_base, list->gl_id);
	glBindVertexArray(0);
	glUseProgram(context->gpu_program.gl_id);
	glBindVertexArray(context->vao_id);
	list->gl_nodes_location = glGetUniformBlockIndex(
		context->gpu_program.gl_id, list->gl_name);
	list->gl_n_nodes_location = glGetUniformLocation(
		context->gpu_program.gl_id, list->gl_n_name);
	glBindVertexArray(0);
	glUseProgram(0);
	return (list);
}

t_ubufferlist	*ubufferlist_addnode(t_ubufferlist *const list,
		t_ubuffernode *const node)
{
	t_ubuffernode	*ptr;

	if (list->first_node)
	{
		ptr = list->first_node;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = node;
		node->prev = ptr;
		node->next = NULL_NODE;
	}
	else
	{
		list->first_node = node;
		node->prev = NULL_NODE;
		node->next = NULL_NODE;
	}
	node->index = list->n_nodes;
	node->list = list;
	++(list->n_nodes);
	return (list);
}

t_ubufferlist	*ubufferlist_bind_data(t_ubufferlist *const list,
		const GLuint program_id)
{
	glUniformBlockBinding(program_id, list->gl_nodes_location, list->gl_base);
	glUniform1iv(list->gl_n_nodes_location, 1, &list->n_nodes);
	return (list);
}

t_ubuffernode	*ubufferlist_fetch_node(t_ubufferlist *const list,
		void *const node_id)
{
	t_ubuffernode	*node;

	node = list->first_node;
	while (node && node->id != node_id)
		node = node->next;
	return (node);
}

t_ubuffernode	*ubufferlist_fetch_node_from_index(t_ubufferlist *const list,
		const int node_index)
{
	t_ubuffernode	*node;

	node = list->first_node;
	while (node && node->index != node_index)
		node = node->next;
	return (node);
}
