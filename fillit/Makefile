# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/07 09:01:58 by rcepre       #+#   ##    ##    #+#        #
#    Updated: 2018/11/07 16:14:27 by rcepre      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fillit

GRAPHIC = no

CC= clang

ifeq ($(GRAPHIC), yes)
	CFLAGS= -Wall -Wextra -Werror -DGRAPHIC=1
else ifeq ($(GRAPHIC), step)
	CFLAGS= -Wall -Wextra -Werror -DGRAPHIC=2
else ifeq ($(GRAPHIC), crazy)
	CFLAGS= -Wall -Wextra -Werror -DGRAPHIC=3
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
	crazy_display.c \

HEADER = ./fillit.h

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
	LINK = "\t$(PINK)fillit\t\t\t$(WHITE)"
	MAKE_LIB =  "$(YELLOW)libft:\t$(RED)make $(YELLOW)libft\t\t$(WHITE)"
	USAGE = "\033[0;29m\tFor a colored static display, use make [...] GRAPHIC=yes\n\
	\tFor a step by step animation of the algorithm, use make [...] GRAPHIC=step\n\
	\tFor an awesome,  tasty and crispy display, use  make [...] GRAPHIC=crazy\n"

####################################RULES######################################

$(NAME): $(OBJECT) $(HEADER)
	@printf  $(MAKE_LIB)
	@(cd $(LIBFT_PATH) && make) > /dev/null
	@printf "$(OK)"
	@printf $(LINK)
	@$(CC) $(CFLAGS) $(OBJECT) -I $< -L $(LIBFT_PATH) -lft -o $(NAME)
	@printf "$(OK)"
	@printf $(USAGE)
%.o: %.c
	@printf "\033[0;36m>>>\tCompiling: $? ..."
	@$(CC) -c $(CFLAGS) -I $(HEADER) $?
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
