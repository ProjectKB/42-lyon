# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/07 09:01:58 by rcepre       #+#   ##    ##    #+#        #
#    Updated: 2018/11/20 16:29:07 by loiberti    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = printf

CC= clang

SRC = ./list_tools.c \
	./parse_string.c \
	./stock_for_parsing.c \
	./tools.c \
	./arg.c \
	./main.c \
	./fix_impossible_flag.c \

HEADER = ./printf.h

OBJECT = $(SRC:.c=.o)

all: $(NAME)

LIBFT_PATH = ./libft

####################################TEXT########################################
	RED = \033[1;31m
	OK  = \033[1;32m[OK]\n
	WHITE = \033[0;29m
	YELLOW = \033[1;33m
	PINK = \033[1;35m
	RM_PRINTF_OBJ = "$(PINK)printf :\t$(RED)rm $(PINK)objects\t\t$(WHITE)"
	RM_LIB_OBJ = "\n$(YELLOW)libft:\t\t$(RED)rm $(YELLOW)objects\t\t$(WHITE)"
	RM_LIB = "\t$(PINK)rm libft.a\t\)$(WHITE)"
	RM_EXEC = "\t\t$(RED)rm $(PINK)exec\t\t\t$(WHITE)"
	MAKE_PRINTF = "$(PINK)printf :\t$(RED)make $(PINK)printf\t\t$(WHITE)"
	MAKE_LIB =  "\n$(YELLOW)libft :\t\t$(RED)make $(YELLOW)libft\t\t$(WHITE)"
####################################RULES######################################

$(NAME): $(OBJECT) $(HEADER)
	@(cd $(LIBFT_PATH) && make) > /dev/null
	@printf  $(MAKE_LIB)
	@printf "$(OK)"
	@$(CC) $(CFLAGS) $(OBJECT) -I $< -L $(LIBFT_PATH) -lft -o $(NAME)
	@printf $(MAKE_PRINTF)
	@printf "$(OK)\n"
	
%.o: %.c
	@printf "\033[0;36m>>>\tCompiling: $? ..."
	@$(CC) -c $(CFLAGS) -I $(HEADER) $?
	@printf "   [ok]$(WHITE)\n"


clean:
	@printf $(RM_LIB_OBJ)
	@(cd $(LIBFT_PATH) && make $@) > /dev/null
	@printf "$(OK)"
	@printf $(RM_PRINTF_OBJ)
	@rm -rf $(OBJECT)
	@printf "$(OK)"

fclean: clean
	@(cd $(LIBFT_PATH) && make $@) > /dev/null
	@printf $(RM_EXEC)
	@rm -rf $(NAME)
	@printf "$(OK)\n"

re: fclean all
	@(cd $(LIBFT_PATH) && make $@) > /dev/null

.PHONY: clean fclean
