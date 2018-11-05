# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcepre <rcepre@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/16 09:13:44 by rcepre            #+#    #+#              #
#    Updated: 2018/11/01 14:56:06 by loiberti    ###    #+. /#+    ###.fr      #
#                                                                              #
# **************************************************************************** #
# **************************************************************************** #

NAME = fillit

CC= clang

CFLAGS= -Wall -Wextra -Werror -g 

SRC = *.c

HEADER_PATH = .

OBJECT = $(SRC:.c=.o)

LIBFT_PATH = ./libft/.

#TEXT

		RM_OBJ = "\t\033[1;32mrm objects\t\t\033[1;32m[OK]\033[1m"
		RM_LIB = "\t\033[1;35mrm libft.a\t\t\033[1;32m[OK]\033[1m"
		RM_EXEC = "\t\033[1;35mrm fillit\t\t\033[1;32m[OK]\033[1m"
		COMPILING = "\t\033[1;34mfillit compilation\t\033[1;32m[OK]\033[1m"

all: $(NAME)
	@$(CC) $(CFLAGS) $(OBJECT) -L $(LIBFT_PATH) -lft  -o $(NAME)

$(NAME): $(OBJECT)
	@(cd $(LIBFT_PATH) && $(MAKE))
	@echo $(COMPILING)
#	@echo "\033[1;31m   (_)     | |         | |                 "
#	@echo "\033[1;32m    _  ___ | |__     __| | ___  _ __   ___ "
#	@echo "\033[1;33m   | |/ _ \\| '_ \\   / _\` |/ _ \\| '_ \\ / _ \\"
#	@echo "\033[1;34m   | | (_) | |_) | | (_| | (_) | | | |  __/"
#	@echo "\033[1;35m   | |\___/|_.__/   \__,_|\___/|_| |_|\___|"
#	@echo "\033[1;36m  _/ |                                     "
#	@echo "\033[1;31m |__/                                      "

%.o: %.c
	@$(CC) $(CFLAGS) -c $(SRC) -I $(HEADER_PATH)

clean:
	@rm -rf $(OBJECT)
	@echo $(RM_OBJ)


fclean: clean
	@rm -fr $(NAME)
	@echo $(RM_EXEC)

re: fclean all

relib: re
	@echo $(RM_LIB)
	@(cd $(LIBFT_PATH) && $(MAKE) re)

.PHONY: clean fclean
