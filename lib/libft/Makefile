# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: calemany <calemany@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 19:54:15 by calemany          #+#    #+#              #
#    Updated: 2017/01/26 05:12:59 by rmc-coma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			libft.a

SRCPATH =		src/
HDRPATH =		includes/
OBJPATH =		obj/

SRCS_STRING =	ft_atoi.c \
				ft_bzero.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_islower.c \
				ft_isupper.c \
				ft_isascii.c \
				ft_isblank.c \
				ft_isdigit.c \
				ft_isxdigit.c \
				ft_isquote.c \
				ft_isprint.c \
				ft_isspace.c \
				ft_itoa.c \
				ft_memalloc.c \
				ft_memccpy.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memdel.c \
				ft_memmove.c \
				ft_memset.c \
				ft_strappend.c \
				ft_strassign.c \
				ft_strcat.c \
				ft_strchr.c \
				ft_strclean.c \
				ft_strclr.c \
				ft_strcmp.c \
				ft_strcount.c \
				ft_strcountend.c \
				ft_strcpy.c \
				ft_strdel.c \
				ft_strdup.c \
				ft_strequ.c \
				ft_strfree.c \
				ft_strisnbr.c \
				ft_striter.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlen.c \
				ft_strmap.c \
				ft_strmapi.c \
				ft_strncat.c \
				ft_strncmp.c \
				ft_strncpy.c \
				ft_strnequ.c \
				ft_strnew.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strsep.c \
				ft_strsplit.c \
				ft_strsplit_str.c \
				ft_strstr.c \
				ft_strsub.c \
				ft_strsub2.c \
				ft_strsum.c \
				ft_strtabfree.c \
				ft_strtoint.c \
				ft_strtouns.c \
				ft_strhextoint.c \
				ft_strhextouns.c \
				ft_strtrim.c \
				ft_tolower.c \
				ft_toupper.c

SRCS_OUTPUT =	ft_putchar.c \
				ft_putchar_fd.c \
				ft_putendl.c \
				ft_putendl_fd.c \
				ft_putline_fd.c \
				ft_putnbr.c \
				ft_putnbr_fd.c \
				ft_putstr.c \
				ft_putstr_fd.c \
				ft_putnchar.c \
				ft_putnchar_fd.c \
				ft_putchar.c \
				ft_putchar_fd.c \
				ft_putendl.c \
				ft_putendl_fd.c \
				ft_putnbr.c \
				ft_putnbr_fd.c \
				ft_putstr.c \
				ft_putnstr.c \
				ft_putstr_fd.c \
				ft_putnstr_fd.c \
				ft_putnchar.c \
				ft_putnchar_fd.c \
				ft_put_fd.c \
				ft_put.c \
				ft_putint_fd.c \
				ft_putuint_fd.c \
				ft_putint.c \
				ft_putuint.c \
				ft_puthex.c \
				ft_puthex_fd.c \
				ft_putaddr.c \
				ft_putaddr_fd.c

SRCS_LIST =		ft_lstadd.c \
				ft_lstchr.c \
				ft_lstdel.c \
				ft_lstdelone.c \
				ft_lstinsert.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_lstnew.c \
				ft_lstapp.c

SRCS_PARSE =	ft_strskip.c \
				ft_strreach.c \
				ft_strsearch.c \
				ft_strwordcmp.c \
				ft_strworddup.c \
				ft_strwordend.c \
				ft_strjoinpath.c \
				ft_strwordsplit.c \
				ft_strskipspaces.c \
				ft_tokget.c \
				ft_toksplit.c \
				ft_toksearch.c \
				ft_tokdup.c

HDR_FILES =		ft_string.h \
				ft_output.h \
				ft_parse.h \
				ft_list.h \
				libft.h

SRCS =			$(SRCS_STRING) $(SRCS_OUTPUT) $(SRCS_LIST) $(SRCS_PARSE)
HDRS =			$(HDRS_FILES:%=includes/%)

OBJS =			$(SRCS:%.c=$(OBJPATH)%.o)

FLAGS =			-Wall -Wextra -Werror

all: $(NAME)

$(OBJPATH)%.o: $(SRCPATH)%.c
	@echo "$(NAME): compiling $<"
	@mkdir -p $(@D)
	@gcc $(FLAGS) -o $@ -c $< -I $(HDRPATH)

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
