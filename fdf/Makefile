# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/07 09:01:58 by rcepre       #+#   ##    ##    #+#        #
#    Updated: 2018/12/18 07:11:39 by loiberti    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fdf

CC= clang

CFLAGS= -Wall -Wextra -Werror -g

SRC_DIR = .

SRC = $(SRC_DIR)/check_errors.c \
	$(SRC_DIR)/display.c \
	$(SRC_DIR)/free.c \
	$(SRC_DIR)/fill_image.c \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/jordan.c \
	$(SRC_DIR)/event.c \
	$(SRC_DIR)/color.c \
	$(SRC_DIR)/matrix.c \
	$(SRC_DIR)/move_map.c \
	$(SRC_DIR)/tools.c \
	$(SRC_DIR)/parser.c \
	$(SRC_DIR)/xiaolin.c \

HEADER = ./fdf.h
LIBFT_PATH = ./libft
LIBFT_OBJ = $(LIBFT_PATH)/*.o

OBJ_DIR = objects
OBJECT = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
LMLX = ./minilibx_macos/libmlx.a
FRAMEWORK = -framework OpenGL -framework Appkit

all: $(NAME)

####################################TEXT########################################
RED = \033[1;31m
OK  = \033[1;32m[OK]\n
WHITE = \033[0;29m
YELLOW = \033[1;33m
PINK = \033[1;35m
RM_PRINTF_OBJ = "$(PINK)fdf :\t\t$(RED)rm $(PINK)objects\t\t$(WHITE)"
RM_LIB_OBJ = "\n$(YELLOW)libft:\t\t$(RED)rm $(YELLOW)objects\t\t$(WHITE)"
RM_LIB = "\t$(YELLOW)rm libft.a\t$(WHITE)"
RM_EXEC = "\t\t$(RED)rm $(PINK)exec\t\t\t$(WHITE)"
MAKE_PRINTF = "$(PINK)fdf :\t\t$(RED)make $(PINK)fdf\t\t$(WHITE)"
MAKE_LIB =  "\n$(YELLOW)libft :\t\t$(RED)make $(YELLOW)libft\t\t$(WHITE)"
####################################RULES######################################



$(NAME): $(OBJECT) $(HEADER)
	@(cd $(LIBFT_PATH) && make) > /dev/null
	@printf  $(MAKE_LIB)
	@printf "$(OK)"
	@$(CC) $(CFLAGS) -L $(LIBFT_PATH) -lft $(OBJECT) -o $@ $(LMLX) $(FRAMEWORK)
	@printf $(MAKE_PRINTF)
	@printf "$(OK)\n"

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
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
