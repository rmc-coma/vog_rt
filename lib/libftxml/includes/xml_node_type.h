/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_node_type.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 14:21:51 by calemany          #+#    #+#             */
/*   Updated: 2016/09/26 14:21:51 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XML_NODE_TYPE_H
# define XML_NODE_TYPE_H

typedef enum	e_xml_node_type
{
	XML_NODE_NULL,
	XML_NODE_ELEMENT,
	XML_NODE_CONTENT
}				t_xml_node_type;

#endif
