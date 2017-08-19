# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: calemany <calemany@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/31 11:55:09 by calemany          #+#    #+#              #
#    Updated: 2016/09/26 17:01:20 by calemany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			libftxml.a

SRCPATH =		src/
OBJPATH =		obj/
LIBPATH =		../
HDRPATH =		includes/ \
				$(LIBPATH)libft/includes

SRCS =			xml_token.c \
				xml_token_set.c \
				xml_token_list.c \
				xml_entity_reference.c \
				xml_node.c \
				xml_element.c \
				xml_element_parse.c \
				xml_element_parse_children.c \
				xml_element_parse_attributes.c \
				xml_node_vector.c \
				xml_content.c \
				xml_error.c \
				xml_error_make.c \
				xml_word.c \
				xml_parse.c

HDRS_FILES =	xml_token.h \
				xml_entity_reference.h \
				xml_node.h \
				xml_element.h \
				xml_node_vector.h \
				xml_content.h \
				xml_error.h \
				xml_word.h \
				xml_parse.h

HDRS =			$(HDRS_FILES:%=includes/%)
OBJS =			$(SRCS:%.c=$(OBJPATH)%.o)

FLAGS =			-Wall -Wextra -Werror

ADDHDR =		$(HDRPATH:%=-I%)

all: $(NAME)

$(OBJPATH)%.o: $(SRCPATH)%.c $(HDRS)
	@echo "$(NAME): compiling $<"
	@mkdir -p $(@D)
	@gcc $(FLAGS) -o $@ -c $< $(ADDHDR)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(NAME): done"

clean:
	@echo "$(NAME): cleaning..."
	@/bin/rm -f $(OBJS)
	@echo "$(NAME): done"

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
