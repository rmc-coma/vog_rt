/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 17:43:34 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/03 06:52:53 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include <SDL2/SDL.h>

# include "window.h"
# include "scene.h"
# include "context.h"
# include "libftxml.h"
# include "xml_parsing.h"
# include "bool.h"

# define KEY_FUNC 			(void *const, const Uint32, void *const)
# define KEY_FUNC_CAST(F)	(void *(*)KEY_FUNC)(F)
# define INPUT_BOUND_KEYS	11
# define KEY_FUNC_COUNT		15

typedef enum	e_key_code
{
	KC_NONE,
	KC_Q = SDL_SCANCODE_Q,
	KC_W = SDL_SCANCODE_W,
	KC_E = SDL_SCANCODE_E,
	KC_R = SDL_SCANCODE_R,
	KC_T = SDL_SCANCODE_T,
	KC_Y = SDL_SCANCODE_Y,
	KC_U = SDL_SCANCODE_U,
	KC_I = SDL_SCANCODE_I,
	KC_O = SDL_SCANCODE_O,
	KC_P = SDL_SCANCODE_P,
	KC_A = SDL_SCANCODE_A,
	KC_S = SDL_SCANCODE_S,
	KC_D = SDL_SCANCODE_D,
	KC_F = SDL_SCANCODE_F,
	KC_G = SDL_SCANCODE_G,
	KC_H = SDL_SCANCODE_H,
	KC_J = SDL_SCANCODE_J,
	KC_K = SDL_SCANCODE_K,
	KC_L = SDL_SCANCODE_L,
	KC_Z = SDL_SCANCODE_Z,
	KC_X = SDL_SCANCODE_X,
	KC_C = SDL_SCANCODE_C,
	KC_V = SDL_SCANCODE_V,
	KC_B = SDL_SCANCODE_B,
	KC_N = SDL_SCANCODE_N,
	KC_M = SDL_SCANCODE_M,
	KC_1 = SDL_SCANCODE_1,
	KC_2 = SDL_SCANCODE_2,
	KC_3 = SDL_SCANCODE_3,
	KC_4 = SDL_SCANCODE_4,
	KC_5 = SDL_SCANCODE_5,
	KC_6 = SDL_SCANCODE_6,
	KC_7 = SDL_SCANCODE_7,
	KC_8 = SDL_SCANCODE_8,
	KC_9 = SDL_SCANCODE_9,
	KC_0 = SDL_SCANCODE_0,
	KC_LCTRL = SDL_SCANCODE_LCTRL,
	KC_LSHIFT = SDL_SCANCODE_LSHIFT,
	KC_LGUI = SDL_SCANCODE_LGUI,
	KC_LALT = SDL_SCANCODE_LALT,
	KC_LEFT = SDL_SCANCODE_LEFT,
	KC_RIGHT = SDL_SCANCODE_RIGHT,
	KC_UP = SDL_SCANCODE_UP,
	KC_DOWN = SDL_SCANCODE_DOWN,
	KC_SPACE = SDL_SCANCODE_SPACE,
	KC_GRAVE = SDL_SCANCODE_GRAVE,
	KC_RETURN = SDL_SCANCODE_RETURN,
	KEY_CODE_COUNT = 47
}				t_key_code;

typedef enum	e_key_type
{
	KT_NONE,
	KT_LIVE,
	KT_SWITCH,
	KEY_TYPE_COUNT = 2
}				t_key_type;

typedef	struct	s_mbutton
{
	t_bool				is_down;
	Uint8				scancode;
	void				*(*func)(void *const, const Uint32);
	t_ivec2				press_coords;
	Uint32				press_timestamp;
	Uint32				handle_timestamp;
	void				*clicked;
}				t_mbutton;

typedef struct	s_key
{
	t_bool				is_down;
	Uint8				scancode;
	t_key_type			type;
	void				*(*func)(void *const, const Uint32, void *const);
	Uint32				press_timestamp;
	Uint32				handle_timestamp;
}				t_key;

typedef struct	s_input
{
	t_bool				writing;
	char				*entry;
	SDL_Event			events;
	t_key				**keys;
	int					n_keys;
	t_mbutton			mbuttons[2];
}				t_input;

t_input			*input_init(t_input *const input);
int				input_scan(t_input *const input, t_context *const context,
					t_gui *const gui, SDL_Event *const events);
int				input_scan_write(t_input *const input, t_context *const context,
				t_gui *const gui, SDL_Event *const events);
t_input			*input_handle(t_input *const input, t_context *const context,
					t_gui *const gui, t_scene *const scene);
t_input			*input_handle_key(t_input *const input, t_scene *const scene,
					t_context *const context, t_gui *const gui);
t_input			*input_handle_mouse(t_input *const input, t_scene *const scene,
					t_gui *const gui);
t_input			*input_set_keys_down(t_input *const input,
					SDL_Event *const events);
t_input			*input_set_keys_up(t_input *const input,
					SDL_Event *const events);
int				input_parse(t_input *const input, t_xml_element const *elem);

t_key			*key_new(void);
t_key			*key_init(t_key *const key);
t_key			*key_set(t_key *const key, const Uint8 scancode,
				void *(*func)(void *const, const Uint32, void *const),
				const t_key_type type);
t_key			**keys_switch_type_cam(t_key **key);
t_key			**keys_switch_type_obj(t_key **key);
t_key			**keys_switch_type_lit(t_key **key);
int				key_parse(t_key *const key, t_xml_element const *elem);

t_mbutton		mbutton(const int is_down, const Uint32 press_timestamp,
					const t_ivec2 press_coords);
t_mbutton		*mbutton_press(t_mbutton *const mbutton, t_gui *const gui,
					t_input *const input, void **const clicked);
t_mbutton		*mbutton_unpress(t_mbutton *const mbutton, t_gui *const gui,
					void **const clicked);

#endif
