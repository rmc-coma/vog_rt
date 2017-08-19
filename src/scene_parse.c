/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 03:51:40 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/02/03 03:54:26 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "object.h"
#include "light.h"
#include "camera.h"
#include "xml_parsing.h"
#include "libftxml.h"

static int	parse_camera(t_scene *scene, t_xml_element const *elem)
{
	t_xml_element const	*child;
	int					err;
	t_camera			*camera;

	err = 0;
	child = xml_element_find_child(elem, "camera");
	if (child)
	{
		camera = camera_new();
		err = camera_parse(camera, child);
		if (!err)
			scene_add_camera(scene, camera, 0, 0);
		else
			free(camera);
	}
	return (err);
}

static int	parse_objects(t_scene *scene, t_xml_element const *elem)
{
	t_xml_element const *objects_elem;
	t_xml_node const	*node;
	t_xml_node const	*end;
	int					err;
	t_object			*object;

	err = 0;
	if ((objects_elem = xml_element_find_child(elem, "objects")))
	{
		node = objects_elem->children;
		end = node + objects_elem->child_count;
		while (node != end && !err)
		{
			if (node->type == XML_NODE_ELEMENT)
			{
				object = object_new();
				err = object_parse(object, &node->element);
				err ? free(object) : scene_add_object(scene, object, 0, 0);
			}
			++node;
		}
	}
	return (err);
}

static int	parse_lights(t_scene *scene, t_xml_element const *elem)
{
	t_xml_element const *lights_elem;
	t_xml_node const	*node;
	t_xml_node const	*end;
	int					err;
	t_light				*light;

	err = 0;
	if ((lights_elem = xml_element_find_child(elem, "lights")))
	{
		node = lights_elem->children;
		end = node + lights_elem->child_count;
		while (node != end && !err)
		{
			if (node->type == XML_NODE_ELEMENT)
			{
				light = light_new();
				err = light_parse(light, &node->element);
				err ? free(light) : scene_add_light(scene, light, 0, 0);
			}
			++node;
		}
	}
	return (err);
}

int			scene_parse(t_scene *scene, t_xml_element const *elem)
{
	int		err;

	err = parse_camera(scene, elem);
	if (!err)
		err = parse_objects(scene, elem);
	if (!err)
		err = parse_lights(scene, elem);
	return (err);
}
