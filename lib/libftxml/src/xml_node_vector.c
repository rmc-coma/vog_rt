/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_node_vector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 14:20:35 by calemany          #+#    #+#             */
/*   Updated: 2016/09/26 17:15:14 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xml_node_vector.h"
#include "xml_node.h"
#include "xml_error.h"

#include <stdlib.h>

void		xml_node_vector_init(t_xml_node_vector *v)
{
	v->tab = NULL;
	v->capacity = 0;
	v->size = 0;
}

void		xml_node_vector_free(t_xml_node_vector *v)
{
	size_t	i;

	i = 0;
	while (i < v->size)
	{
		xml_node_free(&v->tab[i]);
		++i;
	}
	free(v->tab);
	v->tab = NULL;
	v->size = 0;
	v->capacity = 0;
}

t_xml_error	xml_node_vector_resize(t_xml_node_vector *v, size_t new_size)
{
	t_xml_node	*new_tab;
	size_t		new_cap;
	int			i;

	if (new_size > v->capacity)
	{
		new_cap = (v->capacity > 2 ? v->capacity : 2);
		while (new_cap < new_size)
			new_cap *= 2;
		new_tab = (t_xml_node*)malloc(new_cap * sizeof(t_xml_node));
		if (new_tab == NULL)
			return (xml_error_memory());
		i = -1;
		while (++i < (int)v->size)
			new_tab[i] = v->tab[i];
		free(v->tab);
		v->tab = new_tab;
		v->capacity = new_cap;
	}
	v->size = new_size;
	return (XML_SUCCESS);
}

void		xml_node_vector_clear(t_xml_node_vector *v)
{
	v->size = 0;
}

t_xml_error	xml_node_vector_push_back(t_xml_node_vector *v, t_xml_node *val)
{
	t_xml_error	er;

	er = XML_SUCCESS;
	if (v->size < v->capacity)
		v->tab[v->size++] = *val;
	else
	{
		er = xml_node_vector_resize(v, v->size + 1);
		if (v->tab != NULL)
			v->tab[v->size - 1] = *val;
	}
	return (er);
}
