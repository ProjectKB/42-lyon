# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/07 09:01:58 by rcepre       #+#   ##    ##    #+#        #
#    Updated: 2018/12/02 21:47:18 by angauber    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = puissance4

CC= clang

CFLAGS= -Wall -Wextra -Werror

SRC =	./src/main.c \
		./src/error.c \
		./src/create_board.c \
		./src/lets_play.c \
		./src/check.c \
		./src/check2.c \
		./src/ai.c \
		./src/check_threat.c \
		./src/check_threat_line.c \
		./src/check_threat_column.c \
		./src/check_threat_diagonal.c \
		./src/check_strat.c \
		./src/display_map.c

HEADER = ./include/puissance4.h

OBJECT = $(SRC:.c=.o)

all: $(NAME)

LIBFT_PATH = ./libft

####################################TEXT########################################
	RED = \033[1;31m
	OK  = \033[1;32m[OK]\n
	WHITE = \033[0;29m
	YELLOW = \033[1;33m
	PINK = \033[1;35m
	RM_OBJ = "\t$(RED)rm $(YELLOW)objects\t\t$(WHITE)"
	RM_LIB_OBJ = "$(YELLOW)libft:\t$(RED)rm $(YELLOW)objects\t\t$(WHITE)"
	RM_LIB = "\t$(PINK)rm libft.a\t\)$(WHITE)"
	RM_EXEC = "\t$(RED)rm $(YELLOW)exec\t\t\t$(WHITE)"
	LINK = "\t$(PINK)Puissance4\t\t$(WHITE)"
	MAKE_LIB =  "$(YELLOW)libft:\t$(RED)make $(YELLOW)libft\t\t$(WHITE)"

####################################RULES######################################

$(NAME): $(OBJECT) $(HEADER)
	@printf  $(MAKE_LIB)
	@(cd $(LIBFT_PATH) && make) > /dev/null
	@printf "$(OK)"
	@printf $(LINK)
	@$(CC) $(CFLAGS) $(OBJECT) -I $< -L $(LIBFT_PATH) -lft -o $(NAME)
	@printf "$(OK)"
%.o: %.c
	@printf "\033[0;36m>>>\tCompiling: $? ..."
	@$(CC) -c $(CFLAGS) -I $(HEADER) $?
	@mv *.o ./src/
	@printf "   [ok]$(WHITE)\n"


clean:
	@printf $(RM_LIB_OBJ)
	@(cd $(LIBFT_PATH) && make $@) > /dev/null
	@printf "$(OK)"
	@printf $(RM_OBJ)
	@rm -rf $(OBJECT)
	@printf "$(OK)"

fclean: clean
	@(cd $(LIBFT_PATH) && make $@) > /dev/null
	@printf $(RM_EXEC)
	@rm -rf $(NAME)
	@printf "$(OK)"

re: fclean all
	@(cd $(LIBFT_PATH) && make $@) > /dev/null

.PHONY: clean fclean
