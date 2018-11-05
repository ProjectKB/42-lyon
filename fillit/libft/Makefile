# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcepre <rcepre@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/16 09:13:44 by rcepre            #+#    #+#              #
#    Updated: 2018/11/01 14:56:37 by loiberti    ###    #+. /#+    ###.fr      #
#                                                                              #
# **************************************************************************** #
# **************************************************************************** #

NAME = libft.a

CC= clang

CFLAGS= -Wall -Wextra -Werror

SRC = 	ft_atoi.c\
		ft_bzero.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_itoa.c\
		ft_lstadd.c\
		ft_lstdel.c\
		ft_lstdelone.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_lstnew.c\
		ft_memalloc.c\
		ft_memccpy.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memdel.c\
		ft_memmove.c\
		ft_memset.c\
		ft_putchar.c\
		ft_putchar_fd.c\
		ft_putendl.c\
		ft_putendl_fd.c\
		ft_putnbr.c\
		ft_putnbr_fd.c\
		ft_putstr.c\
		ft_putstr_fd.c\
		ft_strcat.c\
		ft_strchr.c\
		ft_strclr.c\
		ft_strcmp.c\
		ft_strcpy.c\
		ft_strdel.c\
		ft_strdup.c\
		ft_strequ.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strjoin.c\
		ft_strlcat.c\
		ft_strlen.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strncat.c\
		ft_strncmp.c\
		ft_strncpy.c\
		ft_strnequ.c\
		ft_strnew.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strsplit.c\
		ft_strstr.c\
		ft_strsub.c\
		ft_strtrim.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_strcapitalize.c \
		ft_sort_integer_table.c \
		ft_recursive_power.c \
		ft_putcolor.c \
		ft_check_char.c \
		ft_freedbtab.c \
		ft_putdbstr.c \
		ft_dbstrnew.c \
		ft_strfsub.c \

HEADER_PATH = .

all: $(NAME)

OBJECT = $(SRC:.c=.o)

#TEXT

		RM_OBJ = "\t\033[1;32mrm objects\t\t\033[1;32m[OK]\033[1m"
		RM_LIB = "\t\033[1;35mrm libft.a\t\t\033[1;32m[OK]\033[1m"
		COMPILING = "\t\033[1;34mlibft.a compilation\t\033[1;32m[OK]\033[1m"

$(NAME): $(OBJECT)
	@ar ruc $(NAME) $(OBJECT)
	@ranlib $(NAME)
	@echo $(COMPILING)

%.o: %.c
	@$(CC) $(CFLAGS) -c $(SRC) -I $(HEADER_PATH)


clean:
	@rm -rf $(OBJECT)
#	@echo $(RM_OBJ)


fclean: clean
	@rm -rf $(NAME)
#	@echo $(RM_LIB)

re: fclean all

.PHONY: clean fclean
