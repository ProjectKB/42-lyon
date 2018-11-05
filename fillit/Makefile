# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcepre <rcepre@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/16 09:13:44 by rcepre            #+#    #+#              #
#    Updated: 2018/11/05 14:58:50 by loiberti    ###    #+. /#+    ###.fr      #
#                                                                              #
# **************************************************************************** #
# **************************************************************************** #

NAME = fillit

CC= clang

CFLAGS= -Wall -Wextra -Werror -g 

SRC = ft_check_errors.c\
	ft_check_global.c\
	ft_check_tetriminos.c\
	ft_create_canva.c\
	ft_get_piece.c\
	ft_piece_to_canva.c\
	ft_read_file.c\
	ft_resolve.c\
	ft_stock_pieces.c\
	debug_tools.c\
	main.c\
	utilities.c\


HEADER_PATH = .

OBJECT = $(SRC:.c=.o)

all: $(NAME)


LIBFT_PATH = ./libft/.

#TEXT

		RM_OBJ = "\t\033[1;32mrm objects\t\t\033[1;32m[OK]\033[1m"
		RM_LIB = "\t\033[1;35mrm libft.a\t\t\033[1;32m[OK]\033[1m"
		RM_EXEC = "\t\033[1;35mrm fillit\t\t\033[1;32m[OK]\033[1m"
		COMPILING = "\t\033[1;34mfillit compilation\t\033[1;32m[OK]\033[1m"

$(NAME): $(OBJECT)
	@(cd $(LIBFT_PATH) && $(MAKE))
	@$(CC) $(CFLAGS)  -L $(LIBFT_PATH) -lft  -o $(NAME)  $?
	@echo $(COMPILING)

%.o: %.c
	@$(CC) $(CFLAGS) -c $(SRC) -I $(HEADER_PATH)

clean:
	@(cd $(LIBFT_PATH) && $(MAKE) $@)
	@rm -rf $(OBJECT)
	@echo $(RM_OBJ)

fclean: clean
	@(cd $(LIBFT_PATH) && $(MAKE) $@)
	@rm -fr $(NAME)
	@echo $(RM_EXEC)

re: fclean all
	@(cd $(LIBFT_PATH) && $(MAKE) $@)

.PHONY: clean fclean
