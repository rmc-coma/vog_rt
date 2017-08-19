/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 21:34:51 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/08 18:17:20 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_H
# define GUI_H

# include <SDL2/SDL.h>
# include "img_parsing.h"
# include "vector.h"
# include "gl_include.h"
# include "context.h"
# include "libftxml.h"
# include "xml_parsing.h"
# include "bool.h"
# include "libft.h"

# define FONT_N_CHARS		95
# define FUNC_CAST(func)	(void *(*)(void *, void *, void *, void *))(func)

struct s_input;

typedef struct	s_fontdata
{
	GLint			width;
	GLint			height;
	GLint			letter_width;
}				t_fontdata;

typedef enum	e_form_type
{
	FT_NONE,
	FT_LIST,
	FT_TEXT
}				t_form_type;

typedef enum	e_elem_type
{
	ET_NONE = 0,
	ET_PANEL,
	ET_FORM,
	ET_TEXTBOX,
	ET_BUTTON,
	ET_LOCKER,
	ET_RACK
}				t_elem_type;

typedef enum	e_textbox_type
{
	TT_NONE = -1,
	TT_TEXT = 0,
	TT_FRAMETIME = 1,
	TT_FPS,
	TT_INPUT,
	TT_DRAW,
	TT_GUI,
	TT_DATA,
	TEXTBOX_TYPE_COUNT
}				t_textbox_type;

typedef enum	e_tdata_type
{
	TDT_NONE = -1,
	TDT_TRANSFORM_PX = 0,
	TDT_TRANSFORM_PY = 1,
	TDT_TRANSFORM_PZ,
	TDT_TRANSFORM_RX,
	TDT_TRANSFORM_RY,
	TDT_TRANSFORM_RZ,
	TDT_TRANSFORM_SX,
	TDT_TRANSFORM_SY,
	TDT_TRANSFORM_SZ,
	TDT_LIGHT_INTENSITY,
	TDT_LIGHT_ANGLE,
	TDT_LIGHT_AMBIANT,
	TDT_LIGHT_DIR_X,
	TDT_LIGHT_DIR_Y,
	TDT_LIGHT_DIR_Z,
	TDT_CAMERA_FOV,
	TDT_CAMERA_PHI,
	TDT_CAMERA_THETA,
	TDT_COLOR_R,
	TDT_COLOR_G,
	TDT_COLOR_B,
	TDT_MAT_AMBIANT,
	TDT_MAT_DIFFUSE,
	TDT_MAT_SPEC,
	TDT_MAT_SPEC_RAD,
	TDT_MAT_REFLECT,
	TDT_MAT_REFRAC,
	TDT_MAT_ROUGH,
	TEXTBOX_DATA_TYPE_COUNT
}				t_tdata_type;

typedef enum	e_rvalue_type
{
	RVT_NONE = -1,
	RVT_CAMERA = 0,
	RVT_OBJECT = 1,
	RVT_LIGHT,
	RACK_VALUE_TYPE_COUNT
}				t_rvalue_type;

typedef enum	e_button_type
{
	BT_NONE = -1,
	BT_VSYNC = 0,
	BT_FORM = 1,
	BUTTON_TYPE_COUNT
}				t_button_type;

typedef struct	s_stats
{
	Uint32			frametime;
	Uint32			fps;
	Uint32			inputtime;
	Uint32			drawtime;
	Uint32			guitime;
}				t_stats;

typedef struct	s_rack
{
	t_bool			clicked;
	Uint32			click_timestamp;
	t_ivec2			pos;
	char			*text;
	t_ubuffernode	*value;
	t_rvalue_type	value_type;
	struct s_locker	*parent;
	struct s_rack	*next;
}				t_rack;

typedef struct	s_locker
{
	t_bool			clicked;
	Uint32			click_timestamp;
	GLint			width;
	GLint			height;
	t_ivec2			pos;
	GLint			padding;
	GLuint			bg_color;
	GLuint			color;
	char			*text;
	GLint			rack_height;
	GLint			rack_padding;
	struct s_form	*form;
	t_rack			*active;
	t_rack			*racks;
	int				n_racks;
	void			*(*draw_func)(void *, void *, void *, void *);
	void			*(*click_func)(void *, void *, void *, void *);
}				t_locker;

typedef struct	s_button
{
	t_bool			clicked;
	Uint32			click_timestamp;
	t_button_type	type;
	GLint			width;
	GLint			height;
	t_ivec2			pos;
	GLint			padding;
	GLuint			bg_color;
	GLuint			color;
	char			*text;
	void			*(*click_func)(void *, void *, void *, void *);
}				t_button;

typedef struct	s_textbox
{
	t_bool			clicked;
	Uint32			click_timestamp;
	t_textbox_type	type;
	t_rack			*fetched;
	void			*data;
	t_tdata_type	data_type;
	GLint			width;
	GLint			height;
	t_ivec2			pos;
	GLint			padding;
	GLuint			bg_color;
	GLuint			color;
	char			*text;
	char			editable;
	struct s_form	*parent;
}				t_textbox;

typedef struct	s_form
{
	GLint			width;
	GLint			height;
	t_ivec2			pos;
	GLint			padding;
	GLuint			bg_color;
	GLuint			color;
	t_form_type		type;
	t_rvalue_type	target;
	char			*text;
	t_textbox		**textboxes;
	int				n_textboxes;
	t_button		**buttons;
	int				n_buttons;
	struct s_locker	*locker;
	struct s_panel	*parent;
}				t_form;

typedef struct	s_panel
{
	GLint			width;
	GLint			height;
	t_ivec2			pos;
	GLint			padding;
	GLuint			bg_color;
	GLuint			color;
	t_textbox		**textboxes;
	int				n_textboxes;
	t_button		**buttons;
	int				n_buttons;
	t_form			**forms;
	int				n_forms;
	t_locker		**lockers;
	int				n_lockers;
}				t_panel;

typedef struct	s_frame
{
	GLuint			gl_id;
	t_ivec2			pos;
	GLint			width;
	GLint			height;
	GLuint			bg_color;
	t_panel			**panels;
	int				n_panels;
	void			*focused;
	t_elem_type		focused_type;
	GLuint			*gl_surface;
	GLuint			gl_surface_size;
	GLint			gl_surface_location;
	GLint			pos_location;
	GLint			width_location;
	GLint			height_location;
}				t_frame;

typedef struct	s_gui
{
	GLuint			*font;
	t_fontdata		fontdata;
	t_frame			frame;
	t_stats			stats;
	GLint			*win_width;
	GLint			*win_height;
	GLint			*context_width;
	GLint			*context_height;
	GLuint			context_width_location;
	GLuint			context_height_location;
	GLuint			gl_frametexture;
	GLuint			gl_frametexture_loc;
	GLint			win_width_location;
	GLint			win_height_location;
	GLuint			vbo_id;
	GLuint			vao_id;
	t_shader		vert_shader;
	t_shader		frag_shader;
	t_program		gpu_program;
	char			*exec_dir;
}				t_gui;

int				gui_init(t_gui *const gui, t_context *const context,
				GLint *const win_width, GLint *const win_height);
int				gui_program_init(t_gui *const gui,
				const char *const exec_filename);
t_gui			*gui_vbo_init(t_gui *const gui);
t_gui			*gui_vao_init(t_gui *const gui);
int				gui_create(t_gui *const gui, t_context *const context,
				const char *const exec_filename);
int				gui_parse(t_gui *gui, t_xml_element const *elem);
t_bool			gui_is_on(t_gui *const gui, t_ivec2 *const pos);

t_gui			*gui_frame_init(t_gui *const gui);
t_gui			*gui_frame_set_color(t_gui *const gui, const GLuint color,
				const t_ivec2 top_left, const t_ivec2 bottom_right);
t_gui			*gui_frame_frame_init(t_gui *const gui);
t_gui			*gui_frame_update(t_gui *const gui, t_scene *const scene);
int				gui_frame_create(t_gui *const gui);
int				gui_frame_parse(t_gui *gui, t_xml_element const *elem);
t_gui			*gui_frame_click(t_gui *const gui, t_ivec2 *const pos,
		void **const clicked);
t_gui			*gui_frame_unclick(t_gui *const gui, void **const clicked);
t_gui			*gui_frame_write(t_gui *const gui, const char entry);
t_gui			*gui_frame_backwrite(t_gui *const gui);
t_gui			*gui_frame_endwrite(t_gui *const gui);

t_panel			*panel_new(void);
t_panel			*panel_init(t_panel *const panel);
int				panel_parse(t_panel *panel, t_xml_element const *elem);
t_panel			*panel_build(t_panel *const panel, t_frame *const frame);
t_panel			*panel_update(t_panel *const panel, t_gui *const gui,
				t_scene *const scene);
t_bool			panel_is_on(t_panel *const panel, t_ivec2 *const pos);

t_form			*form_new(void);
t_form			*form_init(t_form *const form);
t_form			**forms_new(int n_forms);
int				form_parse(t_form *form, t_xml_element const *elem,
					t_panel *parent);
int				form_parse_function(t_form *form, t_xml_element const *elem);
int				form_parse_text(t_form *form, t_xml_element const *elem);
int				form_parse_values(t_form *form, t_xml_element const *elem);
int				form_parse_textboxes(t_form *form, t_xml_element const *elem);
int				form_parse_buttons(t_form *form, t_xml_element const *elem);
t_form			*form_build(t_form *const form, t_frame *const frame);
t_form			*form_update(t_form *const form, t_gui *const gui);
t_bool			form_is_on(t_form *const form, t_ivec2 *const pos);
void			*forms_click(t_form *const *forms, const int n_forms,
					t_frame *const frame, t_ivec2 *const pos);

t_textbox		*textbox_new(void);
t_textbox		**textboxes_new(int n_textboxes);
t_textbox		*textbox_init(t_textbox *const textbox);
int				textbox_parse(t_textbox *textbox, t_xml_element const *elem,
					t_form *parent);
t_textbox		*textbox_build(t_textbox *const textbox, t_frame *const frame);
t_textbox		*textbox_update(t_textbox *const textbox, t_gui *const gui);
t_bool			textbox_is_on(t_textbox *const textbox, t_ivec2 *const pos);
t_textbox		*textboxes_click(t_textbox *const *textboxes,
				const int n_textboxes, t_frame *const frame,
				t_ivec2 *const pos);
t_textbox		*textbox_data_fetch(t_textbox *const textbox, t_gui *const gui);
t_textbox		*textbox_append(t_textbox *const textbox, const char entry);

t_button		*button_new(void);
t_button		**buttons_new(int n_buttons);
t_button		*button_init(t_button *const button);
int				button_parse(t_button *button, t_xml_element const *elem);
t_button		*button_build(t_button *const button, t_frame *const frame);
t_button		*button_update(t_button *const button, t_gui *const gui);
t_bool			button_is_on(t_button *const button, t_ivec2 *const pos);
t_button		*buttons_click(t_button *const *buttons, const int n_buttons,
				t_frame *const frame, t_ivec2 *const pos);

t_locker		*locker_new(void);
t_locker		**lockers_new(int n_lockers);
t_locker		*locker_init(t_locker *const locker);
t_locker		*locker_empty(t_locker *const locker);
t_locker		*locker_fill(t_locker *const locker, t_scene *const scene,
				t_gui *const gui);
int				locker_parse(t_locker *locker, t_xml_element const *elem);
t_locker		*locker_build(t_locker *constlocker, t_frame *const frame);
t_locker		*locker_update(t_locker *const locker, t_scene *const scene,
				t_gui *const gui);
void			*lockers_click(t_locker *const *lockers, const int n_lockers,
				t_frame *const frame, t_ivec2 *const pos);
t_bool			locker_is_on(t_locker *const locker, t_ivec2 *const pos);
t_locker		*locker_forms_link(t_locker *const locker,
				t_frame *const frame);

t_rack			*rack_new(void);
t_rack			*rack_init(t_rack *const rack);
t_rack			*rack_build(t_rack *const rack, t_frame *const frame);
t_rack			*rack_update(t_rack *const rack, t_gui *const gui);
t_bool			rack_is_on(t_rack *const rack, t_ivec2 *const pos);
t_rack			*racks_click(t_rack *racks, const int n_racks,
				t_frame *const frame, t_ivec2 *const pos);
int				racks_count(t_rack *racks);

t_gui			*gui_line_update(t_gui *const gui, const t_ivec2 *pos);
t_gui			*gui_write(t_gui *const gui, const char *const str,
				const GLuint color, const t_ivec2 *pos);
t_gui			*gui_clrline(t_gui *const gui, const t_ivec2 *pos);
t_gui			*gui_putstr(t_gui *const gui, const char *const str,
				const GLuint *const color, t_ivec2 *const pos);
t_gui			*gui_putint(t_gui *const gui, const int n,
				const GLuint *const color, t_ivec2 *const pos);
t_gui			*gui_putlist(t_gui *const gui, t_list *list,
				const GLuint *const color, t_ivec2 *const pos);

t_gui			*gui_draw(t_gui *const gui);

#endif
