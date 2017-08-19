/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 06:40:22 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/01 08:15:10 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "xml_parsing.h"
#include "libftxml.h"

static int	parse_code(t_key *key, t_xml_element const *elem)
{
	static t_key_code	codes[KEY_CODE_COUNT] = {
		KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_A, KC_S,
		KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_Z, KC_X, KC_C, KC_V, KC_B,
		KC_N, KC_M, KC_0, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9,
		KC_SPACE, KC_LCTRL, KC_UP, KC_DOWN, KC_LEFT, KC_RIGHT,
		KC_GRAVE, KC_RETURN, KC_LSHIFT
	};
	static char const	*names[KEY_CODE_COUNT] = {
		"q", "w", "e", "r", "t", "y", "u", "i", "o", "p", "a", "s", "d", "f",
		"g", "h", "j", "k", "l", "z", "x", "c", "v", "b", "n", "m", "0", "1",
		"2", "3", "4", "5", "6", "7", "8", "9", "space", "control left",
		"arrow up", "arrow down", "arrow left", "arrow right",
		"grave", "return", "shift left"
	};
	int					err;
	int					i;

	err = parse_enum_element(elem, KEY_CODE_COUNT, names, &i);
	if (!err)
		key->scancode = codes[i];
	return (err);
}

static int	parse_type(t_key *key, t_xml_element const *elem)
{
	static t_key_type	types[KEY_TYPE_COUNT] = {
		KT_LIVE, KT_SWITCH
	};
	static char const	*names[KEY_TYPE_COUNT] = {
		"live", "switch"
	};
	int					err;
	int					i;

	err = parse_enum_element(elem, KEY_TYPE_COUNT, names, &i);
	if (!err)
		key->type = types[i];
	return (err);
}

static int	parse_function(t_key *key, t_xml_element const *elem)
{
	static void			*(*f[15])(void *const, const Uint32, void *const) = {
		KEY_FUNC_CAST(&camera_move_forward), KEY_FUNC_CAST(&camera_move_up),
		KEY_FUNC_CAST(&camera_move_backward), KEY_FUNC_CAST(&camera_move_down),
		KEY_FUNC_CAST(&camera_move_left), KEY_FUNC_CAST(&camera_move_right),
		KEY_FUNC_CAST(&camera_rotate_up), KEY_FUNC_CAST(&camera_rotate_down),
		KEY_FUNC_CAST(&camera_rotate_left), KEY_FUNC_CAST(&camera_rotate_right),
		KEY_FUNC_CAST(&window_vsync_switch),
		KEY_FUNC_CAST(&context_render_switch),
		KEY_FUNC_CAST(&gui_frame_endwrite), KEY_FUNC_CAST(NULL),
		KEY_FUNC_CAST(NULL)
	};
	static char const	*names[KEY_FUNC_COUNT] = {
		"move forward", "move up", "move backward", "move down", "move left",
		"move right", "rot up", "rot down", "rot left", "rot right", "vsync",
		"render", "entry", "rot forward", "rot backward"
	};
	int					err;
	int					i;

	err = parse_enum_element(elem, KEY_FUNC_COUNT, names, &i);
	if (!err)
		key->func = f[i];
	return (err);
}

int			key_parse(t_key *const key, t_xml_element const *elem)
{
	int					err;
	t_xml_element const	*child;

	key_init(key);
	err = 0;
	child = xml_element_find_child(elem, "type");
	err = parse_type(key, child);
	if (!err)
	{
		child = xml_element_find_child(elem, "key");
		err = parse_code(key, child);
	}
	if (!err)
	{
		child = xml_element_find_child(elem, "function");
		err = parse_function(key, child);
	}
	return (err);
}
