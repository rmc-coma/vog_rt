/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textbox_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 04:19:18 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/08 17:35:37 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "ft_str.h"

#define TEXTBOX_INT_COUNT		14

static GLuint	**get_values(t_textbox *textbox, GLuint **values)
{
	values[0] = (GLuint *)&textbox->width;
	values[1] = (GLuint *)&textbox->height;
	values[2] = (GLuint *)&textbox->pos.x;
	values[3] = (GLuint *)&textbox->pos.y;
	values[4] = (GLuint *)(&textbox->bg_color);
	values[5] = (GLuint *)(((unsigned char *)(&textbox->bg_color)) + 1);
	values[6] = (GLuint *)(((unsigned char *)(&textbox->bg_color)) + 2);
	values[7] = (GLuint *)(((unsigned char *)(&textbox->bg_color)) + 3);
	values[8] = (GLuint *)(&textbox->color);
	values[9] = (GLuint *)(((unsigned char *)(&textbox->color)) + 1);
	values[10] = (GLuint *)(((unsigned char *)(&textbox->color)) + 2);
	values[11] = (GLuint *)(((unsigned char *)(&textbox->color)) + 3);
	values[12] = (GLuint *)&textbox->padding;
	values[13] = (GLuint *)&textbox->editable;
	return (values);
}

static int		parse_values(t_textbox *textbox, t_xml_element const *elem)
{
	static char const	*names[TEXTBOX_INT_COUNT] = {
		"width", "height", "x", "y", "bg_color_r", "bg_color_g", "bg_color_b",
		"bg_color_a", "f_color_r", "f_color_g", "f_color_b", "f_color_a",
		"padding", "editable"};
	GLuint				*values[TEXTBOX_INT_COUNT];
	int					err;
	t_ivec2				base;

	get_values(textbox, values);
	base = textbox->pos;
	err = (parse_int_children(elem, TEXTBOX_INT_COUNT, names, (int **)values)
		< 0);
	textbox->pos.x += base.x;
	textbox->pos.y += base.y;
	return (err);
}

static int		parse_data(t_textbox *textbox, t_xml_element const *elem)
{
	static char const		*names[TEXTBOX_DATA_TYPE_COUNT] = {
		"transform_pos_x", "transform_pos_y", "transform_pos_z",
		"transform_rot_x", "transform_rot_y", "transform_rot_z",
		"transform_scl_x", "transform_scl_y", "transform_scl_z",
		"light_intensity", "light_angle", "light_ambiant", "light_dir_x",
		"light_dir_y", "light_dir_z", "camera_fov", "camera_phi",
		"camera_theta", "color_r", "color_g", "color_b", "material_ambiant",
		"material_diffuse", "material_specular", "material_specular_radius",
		"material_reflection", "material_refraction", "material_roughness"
	};
	int						err;
	int						i;

	err = parse_enum_element(xml_element_find_child(elem, "data"),
		TEXTBOX_DATA_TYPE_COUNT, names, &i);
	if (!err)
		textbox->data_type = (t_tdata_type)i;
	return (err);
}

static int		parse_function(t_textbox *textbox, t_xml_element const *elem)
{
	static char const	*names[TEXTBOX_TYPE_COUNT] = {
		"text", "frametime", "fps", "inputtime", "drawtime", "guitime", "list"
	};
	int					err;
	int					i;

	err = parse_enum_element(xml_element_find_child(elem, "function"),
							TEXTBOX_TYPE_COUNT, names, &i);
	if (!err)
	{
		textbox->type = (t_textbox_type)i;
		if (i == TT_DATA)
			parse_data(textbox, elem);
		if (parse_string_element(xml_element_find_child(elem, "text"),
			&textbox->text))
			textbox->text = ft_strdup("Undefined field");
	}
	if ((i >= TEXTBOX_TYPE_COUNT || i < 0) && err)
		return (0);
	else
		textbox->type = (t_textbox_type)i;
	return (err);
}

int				textbox_parse(t_textbox *textbox, t_xml_element const *elem,
					t_form *parent)
{
	int					err;

	err = parse_values(textbox, elem);
	if (!err)
		err = parse_function(textbox, elem);
	textbox->parent = parent;
	return (0);
}
