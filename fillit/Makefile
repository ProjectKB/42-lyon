# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcepre <rcepre@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 15:19:15 by rcepre            #+#    #+#              #
#    Updated: 2018/11/06 19:25:35 by rcepre      ###    #+. /#+    ###.fr      #
#                                                                              #
# **************************************************************************** #

NAME = fillit

GRAPHIC = no

CC= clang

ifeq ($(GRAPHIC), yes)
	CFLAGS= -Wall -Wextra -Werror -DGRAPHIC=1
else ifeq ($(GRAPHIC), step)
	CFLAGS= -Wall -Wextra -Werror -DGRAPHIC=2
else
	CFLAGS= -Wall -Wextra -Werror
endif

SRC = check_errors.c\
	create_canva.c\
	get_piece.c\
	piece_to_canva.c\
	read_file.c\
	resolve.c\
	stock_pieces.c\
	dynamic_display.c\
	main.c\
	utilities.c\
	display.c\

HEADER = ./fillit.h

OBJECT = $(SRC:.c=.o)

all: $(NAME)

LIBFT_PATH = ./libft

#TEXT

		RM_OBJ = "\t\033[1;32mrm objects\t\t\033[1;32m[OK]\033[1m"
		RM_LIB = "\t\033[1;35mrm libft.a\t\t\033[1;32m[OK]\033[1m"
		RM_EXEC = "\t\033[1;35mrm fillit\t\t\033[1;32m[OK]\033[1m"
		COMPILING = "\t\033[1;34mfillit compilation\t\033[1;32m[OK]\033[1m"
		USAGE = "\033[0;29m\tFor a colored static display, use make [...] GRAPHIC=yes\n\
		\tFor a step by step animation of the algorithm, use make [...] GRAPHIC=step\n"

$(NAME): $(OBJECT) $(HEADER)
	@(cd $(LIBFT_PATH) && make) > /dev/null
	@$(CC) $(CFLAGS) $(OBJECT) -I $< -L $(LIBFT_PATH) -lft -o $(NAME)

%.o: %.c
	@$(CC) -c $(CFLAGS) -I $(HEADER) $?

clean:
	@(cd $(LIBFT_PATH) && make $@) > /dev/null
	@rm -rf $(OBJECT)

fclean: clean
	@(cd $(LIBFT_PATH) && make $@) > /dev/null
	@rm -rf $(NAME)

re: fclean all
	@(cd $(LIBFT_PATH) && make $@) > /dev/null

.PHONY: clean fclean
