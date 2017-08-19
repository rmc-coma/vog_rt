# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/29 18:42:04 by calemany          #+#    #+#              #
#    Updated: 2017/03/13 19:11:20 by jleu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean clean_libs fclean_libs fclean_shaders \
	re shaders debug set_debug_mode

UNAME_S = $(shell uname -s)

NAME =			RT
BUILDPATH =		build/
BUILD =			$(BUILDPATH)$(NAME)

SHADBUILDPATH =	$(BUILDPATH)shaders/
CONTEXT_FRAG_BUILD = \
				$(SHADBUILDPATH)context.frag
GUI_FRAG_BUILD = \
				$(SHADBUILDPATH)gui.frag
CONTEXT_VERT_BUILD = \
				$(SHADBUILDPATH)context.vert
GUI_VERT_BUILD = \
				$(SHADBUILDPATH)gui.vert

SRCPATH =		src/
FONTPATH =		font/
OBJPATH =		obj/
LIBPATH =		lib/
HDRPATH =		includes/
SHADPATH =		shaders/
LIBDIRS :=		libft/ \
				libftxml/
LIBDIRS :=		$(LIBDIRS:%=$(LIBPATH)%)
HDRDIRS :=		$(HDRPATH) \
				$(LIBPATH)libft/includes/ \
				$(LIBPATH)libftxml/includes/

ifeq ($(UNAME_S),Linux)
INCLUDE_LIBS :=	-lSDL2 -lm -lGL -lpthread
endif
ifeq ($(UNAME_S),Darwin)
INCLUDE_LIBS := -framework SDL2 -framework OpenGL
endif


INCLUDE_LIBS := $(INCLUDE_LIBS) -lftxml -lft

LIBS :=			libft/libft.a \
				libftxml/libftxml.a
LIBS :=			$(LIBS:%=$(LIBPATH)%)

SRCS =			\
				box.c \
				button.c \
				button_init.c \
				button_parse.c \
				camera.c \
				camera_move.c \
				camera_move2.c \
				camera_parse.c \
				camera_rotate.c \
				cone.c \
				context.c \
				context_init.c \
				context_parse.c \
				cubic.c \
				cylinder.c \
				datamodel.c \
				debug.c \
				double_parse.c \
				ellipsoid.c \
				environment.c \
				error.c \
				form.c \
				form_init.c \
				form_parse.c \
				ft_itoa.c \
				ft_list.c \
				ft_math.c \
				ft_mem.c \
				ft_str.c \
				geometry.c \
				geometry2.c \
				geometry_parse.c \
				get_next_line.c \
				gui.c \
				gui_frame.c \
				gui_frame_init.c \
				gui_frame_parse.c \
				gui_frame_utils.c \
				gui_frame_utils2.c \
				gui_init.c \
				gui_init2.c \
				gui_parse.c \
				gui_put.c \
				gui_utils.c \
				hardware.c \
				hyperboloid.c \
				img_parsing.c \
				img_parsing_bmp.c \
				input.c \
				input_handle.c \
				input_init.c \
				input_parse.c \
				key.c \
				key_parse.c \
				light.c \
				light_parse.c \
				locker.c \
				locker_init.c \
				locker_parse.c \
				locker_utils.c \
				loop.c \
				main.c \
				material.c \
				material_parse.c \
				mbutton.c \
				mesh.c \
				mesh_parse.c \
				mobius.c \
				object.c \
				object_parse.c \
				panel.c \
				panel_init.c \
				panel_parse.c \
				paraboloid.c \
				parameters_parse.c \
				plane.c \
				power_of_ten.c \
				program.c \
				quadric.c \
				rack.c \
				rack_init.c \
				scene.c \
				scene_box.c \
				scene_camera.c \
				scene_cone.c \
				scene_cubic.c \
				scene_cylinder.c \
				scene_ellipsoid.c \
				scene_geometry.c \
				scene_hyperboloid.c\
				scene_light.c \
				scene_material.c \
				scene_mesh.c \
				scene_mobius.c \
				scene_object.c \
				scene_paraboloid.c \
				scene_parse.c \
				scene_plane.c \
				scene_quadric.c \
				scene_sphere.c \
				scene_torus.c \
				scene_transform.c \
				shad_struct.c \
				shader.c \
				sphere.c \
				textbox.c \
				textbox_data.c \
				textbox_init.c \
				textbox_parse.c \
				textbox_utils.c \
				torus.c \
				transform.c \
				transform_move.c \
				transform_move2.c \
				transform_parse.c \
				transform_rotate.c \
				transform_rotate2.c \
				ubufferlist.c \
				ubuffernode.c \
				utils.c \
				vector.c \
				vector2.c \
				vector_op.c \
				vector_parse.c \
				window.c \
				window_parse.c \
				xml_parsing.c \
				xml_parsing_children.c \
				xml_parsing_element.c \
				xml_parsing_float.c \
				xml_parsing_var.c \
				light_move.c \
				light_move2.c \
				light_rotate.c \
				key_switch.c \
				form_parse2.c \
				img.c \
				img_bmp.c

HDRS_FILES =	\
				camera.h \
				cone.h \
				constants.h \
				context.h \
				create_scene.h \
				cylinder.h \
				datamodel.h \
				debug.h \
				environment.h \
				ft_list.h \
				ft_mem.h \
				ft_str.h \
				geometry.h \
				get_next_line.h \
				hardware.h \
				input.h \
				light.h \
				loop.h \
				material.h \
				mesh.h \
				object.h \
				parameters.h \
				plane.h \
				program.h \
				scene.h \
				shader.h \
				sphere.h \
				transform.h \
				ubuffer.h \
				vector.h \
				window.h \
				double_parse.h \
				power_of_ten.h \
				xml_parsing.h \
				torus.h \
				box.h \
				gl_include.h \
				mobius.h \
				quadric.h \
				img_parsing.h \
				gui.h \
				utils.h \
				ft_math.h \
				ellipsoid.h \
				paraboloid.h\
				hyperboloid.h \
				shad_struct.h \
				cubic.h \
				bool.h \
				error.h

CONTEXT_FRAG_FILES = \
				frag_header.frag \
				constant.frag \
				maths.frag \
				polynome4.frag \
				ray.frag \
				intersection.frag \
				aabb.frag \
				quadric.frag \
				torus.frag \
				cubic.frag \
				geometry.frag \
				material.frag \
				mesh.frag \
				transform.frag \
				light.frag \
				object.frag \
				rt_light.frag \
				rt.frag \
				rt_transparency.frag \
				main.frag

CONTEXT_VERT_FILES = \
				context.vert

GUI_FRAG_FILES = \
				gui.frag

GUI_VERT_FILES = \
				gui.vert


HDRS =			$(HDRS_FILES:%=$(HDRPATH)%)
OBJS =			$(SRCS:%.c=$(OBJPATH)%.o)


DEFAULT_FLAGS =	-Wall -Wextra -Werror
CFLAGS :=		$(DEFAULT_FLAGS)
LFLAGS :=		$(DEFAULT_FLAGS)

CLEAN_LIBS =	$(LIBDIRS:%=$(MAKE) -C % clean > /dev/null;)
RM_LIBS =		$(LIBS:%=/bin/rm -f % > /dev/null;)


all: $(BUILD) shaders

debug: set_debug_mode all

set_debug_mode:
	$(eval CFLAGS := $(CFLAGS) -ggdb)

$(OBJPATH)%.o: $(SRCPATH)%.c $(HDRS)
	@echo "$(NAME): compiling $<..."
	@mkdir -p $(@D)
	@gcc $(CFLAGS) -o $@ -c $< $(HDRDIRS:%=-I%)

$(BUILD): $(LIBS) $(OBJS)
	@echo "$(NAME): linking..."
	@mkdir -p $(BUILDPATH)
	@mkdir -p $(BUILDPATH)$(FONTPATH)
	@cp "$(FONTPATH)/ugly.bmp" $(BUILDPATH)$(FONTPATH)
	@cp "parameters.xml" $(BUILDPATH)
	@gcc $(LFLAGS) -o "$(BUILDPATH)$(NAME)" $(OBJS) $(LIBDIRS:%=-L%) $(INCLUDE_LIBS)
	@echo "$(NAME): done"


shaders: $(CONTEXT_FRAG_BUILD) $(CONTEXT_VERT_BUILD) $(GUI_FRAG_BUILD) $(GUI_VERT_BUILD)

$(CONTEXT_FRAG_BUILD): $(CONTEXT_FRAG_FILES:%=$(SHADPATH)%)
	@echo "$(NAME): copying context fragment shaders"
	@mkdir -p $(@D)
	@sed -e '/^$$/d' $(CONTEXT_FRAG_FILES:%=$(SHADPATH)%) > $@
	@echo "$(NAME): done"

$(CONTEXT_VERT_BUILD): $(CONTEXT_VERT_FILES:%=$(SHADPATH)%)
	@echo "$(NAME): copying context vertex shaders"
	@mkdir -p $(@D)
	@sed -e '/^$$/d' $(CONTEXT_VERT_FILES:%=$(SHADPATH)%) > $@
	@echo "$(NAME): done"

$(GUI_FRAG_BUILD): $(GUI_FRAG_FILES:%=$(SHADPATH)%)
	@echo "$(NAME): copying gui fragment shaders"
	@mkdir -p $(@D)
	@sed -e '/^$$/d' $(GUI_FRAG_FILES:%=$(SHADPATH)%) > $@
	@echo "$(NAME): done"

$(GUI_VERT_BUILD): $(GUI_VERT_FILES:%=$(SHADPATH)%)
	@echo "$(NAME): copying gui vertex shaders"
	@mkdir -p $(@D)
	@sed -e '/^$$/d' $(GUI_VERT_FILES:%=$(SHADPATH)%) > $@
	@echo "$(NAME): done"

%.a:
	@echo "$(NAME): compiling $@..."
	@$(MAKE) -s -C $(@D) > /dev/null


clean: clean_$(NAME) clean_libs

clean_$(NAME):
	@echo "$(NAME): cleaning..."
	@/bin/rm -f $(OBJS)

clean_libs:
	@echo "$(NAME): cleaning libs..."
	@$(CLEAN_LIBS)


fclean_shaders:
	@echo "$(NAME): cleaning shaders"
	@/bin/rm -f $(CONTEXT_FRAG_BUILD) $(CONTEXT_VERT_BUILD) $(GUI_FRAG_BUILD) $(GUI_VERT_BUILD)

fclean_libs: clean_libs
	@echo "$(NAME): removing lib builds..."
	@$(RM_LIBS)

fclean: clean_$(NAME) fclean_libs fclean_shaders
	@/bin/rm -f $(BUILD)


re: fclean all
