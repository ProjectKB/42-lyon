# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/07 09:01:58 by rcepre       #+#   ##    ##    #+#        #
#    Updated: 2019/03/14 14:58:54 by loiberti    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = lem_in

CC= clang

CFLAGS= 

SRC_DIR = ./srcs
HEADER_DIR = ./includes

SRC = $(SRC_DIR)/main.c \
	$(SRC_DIR)/parser.c \
	$(SRC_DIR)/tools.c \

HEADER = $(HEADER_DIR)/lem_in.h
LIBFT_PATH = ./libft
LIBFT_OBJ = $(LIBFT_PATH)/*.o

OBJ_DIR = objects
OBJECT = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

####################################TEXT########################################
RED = \033[1;31m
OK  = \033[1;32m[OK]\n
WHITE = \033[0;29m
YELLOW = \033[1;33m
PINK = \033[1;35m
RM_PRINTF_OBJ = "$(PINK)lem_in :\t$(RED)rm $(PINK)objects\t\t$(WHITE)"
RM_LIB_OBJ = "\n$(YELLOW)libft:\t\t$(RED)rm $(YELLOW)objects\t\t$(WHITE)"
RM_LIB = "\t$(YELLOW)rm libft.a\t$(WHITE)"
RM_EXEC = "\t\t$(RED)rm $(PINK)exec\t\t\t$(WHITE)"
MAKE_PRINTF = "$(PINK)lem_in :\t$(RED)make $(PINK)lem_in\t\t$(WHITE)"
MAKE_LIB =  "\n$(YELLOW)libft :\t\t$(RED)make $(YELLOW)libft\t\t$(WHITE)"
####################################RULES######################################



$(NAME): $(OBJECT) $(HEADER)
	@(cd $(LIBFT_PATH) && make) > /dev/null
	@printf  $(MAKE_LIB)
	@printf "$(OK)"
	@$(CC) $(CFLAGS) -I $< -L $(LIBFT_PATH) -lft $(OBJECT) -o $(NAME)
	@printf $(MAKE_PRINTF)
	@printf "$(OK)\n"

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER) | $(OBJ_DIR)
	@printf "\033[0;36m>>>\tCompiling: $? ..."
	@$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<
	@printf "   [ok]$(WHITE)\n"

clean:
	@printf $(RM_LIB_OBJ)
	@(cd $(LIBFT_PATH) && make $@) > /dev/null
	@printf "$(OK)"
	@printf $(RM_PRINTF_OBJ)
	@rm -rf $(OBJ_DIR)
	@printf "$(OK)"

fclean: clean
	@(cd $(LIBFT_PATH) && make $@) > /dev/null
	@printf $(RM_EXEC)
	@printf "$(OK)\n"
	@rm -rf $(NAME)

re: fclean all
	@(cd $(LIBFT_PATH) && make $@) > /dev/null

.PHONY: clean fclean
