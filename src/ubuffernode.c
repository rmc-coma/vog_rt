/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ubuffernode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 20:59:56 by jleu              #+#    #+#             */
/*   Updated: 2017/02/28 21:09:07 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ubuffer.h"
#include "ft_mem.h"
#include "ft_str.h"
#include "debug.h"
#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>

t_ubuffernode	*ubuffernode_new(t_shad_struct const *shad_struct,
		void *const id)
{
	t_ubuffernode	*new;
	GLuint			n_children;

	n_children = shad_struct->n_children;
	new = (t_ubuffernode *)ft_memalloc(sizeof(t_ubuffernode));
	new->has_type = shad_struct->has_type;
	new->n_datas = shad_struct->n_vars;
	new->datas = (GLvoid **)ft_memalloc(sizeof(GLvoid *) * new->n_datas);
	new->index = -1;
	new->parent_index = (void *)0;
	new->n_children = n_children;
	new->children_indexes = (void *)0;
	new->children_lists = (void *)0;
	new->children_nodes = (void *)0;
	if (n_children)
	{
		new->children_indexes =
			(GLint **)ft_memalloc(sizeof(GLint *) * n_children);
		new->children_lists =
			(t_ubufferlist **)ft_memalloc(sizeof(t_ubufferlist *) * n_children);
		new->children_nodes =
			(t_ubuffernode **)ft_memalloc(sizeof(t_ubuffernode *) * n_children);
	}
	new->id = id;
	return (new);
}

t_ubuffernode	*ubuffernode_bind(t_ubuffernode *const child,
		t_ubuffernode *const parent, const GLuint slot)
{
	child->parent_index = &parent->index;
	child->parent_node = parent;
	child->parent_list = parent->list;
	parent->children_indexes[slot] = &child->index;
	parent->children_lists[slot] = child->list;
	parent->children_nodes[slot] = child;
	return (child);
}

t_ubuffernode	*ubuffernode_setdata(t_ubuffernode *const node)
{
	GLuint			i;
	GLuint			j;
	GLuint			offset;

	i = 0;
	if (node->has_type)
		node->datas[i++] = node->id;
	node->datas[i++] = node->parent_index;
	if (node->n_children)
	{
		j = 0;
		while (j < node->n_children)
			node->datas[i++] = node->children_indexes[j++];
	}
	while (i < node->n_datas)
	{
		offset = 0;
		j = i;
		while (--j)
			offset += node->list->datamodel.sizes[j];
		node->datas[i] = node->id + offset
			+ 4 * (node->n_children + node->has_type);
		++i;
	}
	return (node);
}

t_ubuffernode	*ubuffernode_subdata(t_ubuffernode *const node)
{
	GLuint			i;

	glBindBuffer(GL_UNIFORM_BUFFER, node->list->gl_id);
	if (node->datas[0])
	{
		glBufferSubData(GL_UNIFORM_BUFFER, node->list->datamodel.total_size *
			node->index, node->list->datamodel.sizes[0], node->datas[0]);
	}
	i = 1;
	while (i < node->list->datamodel.n_sizes)
	{
		if (node->datas[i])
		{
			glBufferSubData(GL_UNIFORM_BUFFER,
							node->list->datamodel.total_size * node->index +
							node->list->datamodel.offsets[i - 1],
							node->list->datamodel.sizes[i], node->datas[i]);
		}
		++i;
	}
	glBindBuffer(GL_UNIFORM_BUFFER, 0);
	return (node);
}
