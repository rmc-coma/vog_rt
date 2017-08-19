/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_node_vector.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 14:21:57 by calemany          #+#    #+#             */
/*   Updated: 2016/09/26 14:25:40 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XML_NODE_VECTOR_H
# define XML_NODE_VECTOR_H

# include "xml_error.h"

# include <stdlib.h>

union u_xml_node;

typedef struct			s_xml_node_vector
{
	union u_xml_node	*tab;
	size_t				size;
	size_t				capacity;
}						t_xml_node_vector;

void					xml_node_vector_init(t_xml_node_vector *v);
t_xml_error				xml_node_vector_push_back(t_xml_node_vector *v,
		union u_xml_node *val);
t_xml_error				xml_node_vector_resize(t_xml_node_vector *v,
		size_t new_size);
void					xml_node_vector_free(t_xml_node_vector *v);
void					xml_node_vector_clear(t_xml_node_vector *v);

#endif
