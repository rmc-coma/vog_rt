/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_switch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 04:10:20 by jleu              #+#    #+#             */
/*   Updated: 2017/03/01 04:11:20 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "libft.h"
#include "camera.h"
#include "transform.h"

t_key	**keys_switch_type_cam(t_key **key)
{
	key[0]->func = KEY_FUNC_CAST(&camera_move_forward);
	key[1]->func = KEY_FUNC_CAST(&camera_move_backward);
	key[2]->func = KEY_FUNC_CAST(&camera_move_left);
	key[3]->func = KEY_FUNC_CAST(&camera_move_right);
	key[4]->func = KEY_FUNC_CAST(&camera_move_up);
	key[5]->func = KEY_FUNC_CAST(&camera_move_down);
	key[6]->func = KEY_FUNC_CAST(&camera_rotate_up);
	key[7]->func = KEY_FUNC_CAST(&camera_rotate_down);
	key[8]->func = KEY_FUNC_CAST(&camera_rotate_left);
	key[9]->func = KEY_FUNC_CAST(&camera_rotate_right);
	key[10]->func = KEY_FUNC_CAST(NULL);
	key[11]->func = KEY_FUNC_CAST(NULL);
	key[12]->func = KEY_FUNC_CAST(&window_vsync_switch);
	key[13]->func = KEY_FUNC_CAST(&context_render_switch);
	key[14]->func = KEY_FUNC_CAST(&gui_frame_endwrite);
	return (key);
}

t_key	**keys_switch_type_obj(t_key **key)
{
	key[0]->func = KEY_FUNC_CAST(&transform_move_forward);
	key[1]->func = KEY_FUNC_CAST(&transform_move_backward);
	key[2]->func = KEY_FUNC_CAST(&transform_move_left);
	key[3]->func = KEY_FUNC_CAST(&transform_move_right);
	key[4]->func = KEY_FUNC_CAST(&transform_move_up);
	key[5]->func = KEY_FUNC_CAST(&transform_move_down);
	key[6]->func = KEY_FUNC_CAST(&transform_rotate_up);
	key[7]->func = KEY_FUNC_CAST(&transform_rotate_down);
	key[8]->func = KEY_FUNC_CAST(&transform_rotate_left);
	key[9]->func = KEY_FUNC_CAST(&transform_rotate_right);
	key[10]->func = KEY_FUNC_CAST(&transform_rotate_forward);
	key[11]->func = KEY_FUNC_CAST(&transform_rotate_backward);
	key[12]->func = KEY_FUNC_CAST(&window_vsync_switch);
	key[13]->func = KEY_FUNC_CAST(&context_render_switch);
	key[14]->func = KEY_FUNC_CAST(&gui_frame_endwrite);
	return (key);
}

t_key	**keys_switch_type_lit(t_key **key)
{
	key[0]->func = KEY_FUNC_CAST(&light_move_forward);
	key[1]->func = KEY_FUNC_CAST(&light_move_backward);
	key[2]->func = KEY_FUNC_CAST(&light_move_left);
	key[3]->func = KEY_FUNC_CAST(&light_move_right);
	key[4]->func = KEY_FUNC_CAST(&light_move_up);
	key[5]->func = KEY_FUNC_CAST(&light_move_down);
	key[6]->func = KEY_FUNC_CAST(&light_rotate_up);
	key[7]->func = KEY_FUNC_CAST(&light_rotate_down);
	key[8]->func = KEY_FUNC_CAST(&light_rotate_left);
	key[9]->func = KEY_FUNC_CAST(&light_rotate_right);
	key[10]->func = KEY_FUNC_CAST(NULL);
	key[11]->func = KEY_FUNC_CAST(NULL);
	key[12]->func = KEY_FUNC_CAST(&window_vsync_switch);
	key[13]->func = KEY_FUNC_CAST(&context_render_switch);
	return (key);
}
