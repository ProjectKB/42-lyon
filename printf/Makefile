# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: rcepre <rcepre@student.42.fr>              +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/07 09:01:58 by rcepre       #+#   ##    ##    #+#        #
#    Updated: 2018/11/28 23:37:56 by loiberti    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libftprintf.a

CC= clang

SRC = ./list_tools.c \
	./parse_string.c \
	./stock_for_parsing.c \
	./tools.c \
	./parse_args.c \
	./fix_impossible_flag.c \
	./flag.c \
	./field.c \
	./float.c \
	./precision.c \
	./length_modifier.c \
	./transform_chain.c \
	./final_display.c \
	./libft/ft_atoi.c\
	./libft/ft_utoi.c\
	./libft/ft_bzero.c\
	./libft/ft_isalnum.c\
	./libft/ft_isalpha.c\
	./libft/ft_isascii.c\
	./libft/ft_isdigit.c\
	./libft/ft_isprint.c\
	./libft/ft_itoa.c\
	./libft/ft_utoa.c\
	./libft/ft_itoa_base.c\
	./libft/ft_atoi_base.c\
	./libft/ft_lstadd.c\
	./libft/ft_lstdel.c\
	./libft/ft_lstdelone.c\
	./libft/ft_lstiter.c\
	./libft/ft_lstmap.c\
	./libft/ft_lstnew.c\
	./libft/ft_memalloc.c\
	./libft/ft_memccpy.c\
	./libft/ft_memchr.c\
	./libft/ft_memcmp.c\
	./libft/ft_memcpy.c\
	./libft/ft_memdel.c\
	./libft/ft_memmove.c\
	./libft/ft_memset.c\
	./libft/ft_putchar.c\
	./libft/ft_putchar_fd.c\
	./libft/ft_putendl.c\
	./libft/ft_putendl_fd.c\
	./libft/ft_putnbr.c\
	./libft/ft_putnbr_fd.c\
	./libft/ft_floatlen.c \
	./libft/ft_putstr.c\
	./libft/ft_putstr_fd.c\
	./libft/ft_strcat.c\
	./libft/ft_strchr.c\
	./libft/ft_strclr.c\
	./libft/ft_strcmp.c\
	./libft/ft_strcpy.c\
	./libft/ft_strdel.c\
	./libft/ft_strdup.c\
	./libft/ft_strequ.c\
	./libft/ft_striter.c\
	./libft/ft_striteri.c\
	./libft/ft_strjoin.c\
	./libft/ft_strlcat.c\
	./libft/ft_strlen.c\
	./libft/ft_strmap.c\
	./libft/ft_strmapi.c\
	./libft/ft_strncat.c\
	./libft/ft_strncmp.c\
	./libft/ft_strncpy.c\
	./libft/ft_strnequ.c\
	./libft/ft_strnew.c\
	./libft/ft_strnstr.c\
	./libft/ft_strrchr.c\
	./libft/ft_strsplit.c\
	./libft/ft_strstr.c\
	./libft/ft_strsub.c\
	./libft/ft_strtrim.c\
	./libft/ft_tolower.c\
	./libft/ft_toupper.c\
	./libft/ft_strcapitalize.c \
	./libft/ft_sort_integer_table.c \
	./libft/ft_recursive_power.c \
	./libft/ft_recursive_npower.c \
	./libft/ft_putcolor.c \
	./libft/ft_check_char.c \
	./libft/ft_freedbtab.c \
	./libft/ft_putdbstr.c \
	./libft/ft_dbstrnew.c \
	./libft/ft_strfsub.c \
	./libft/ft_getchar.c \
	./libft/ft_strupcase.c \
	./libft/ft_lowercase.c \
	./libft/ft_swap.c \
	./libft/ft_strcapitalize.c \
	./libft/ft_strrev.c \

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
	@ar rucs $(NAME) $(OBJECT)
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
