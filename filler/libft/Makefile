# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/02/14 18:49:50 by loiberti     #+#   ##    ##    #+#        #
#    Updated: 2019/03/08 16:32:49 by loiberti    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libft.a

CC= clang

CFLAGS= -Wall -Wextra -Werror -g

SRC = 	ft_atoi.c\
		ft_utoi.c\
		ft_bzero.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_itoa.c\
		ft_utoa.c\
		ft_itoa_base.c\
		ft_atoi_base.c\
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
		ft_floatlen.c \
		ft_putstr.c\
		ft_putstr_fd.c\
		ft_strcat.c\
		ft_strchr.c\
		ft_strclr.c\
		ft_strcmp.c\
		ft_strcpy.c\
		ft_strdel.c\
		ft_strdup.c\
		ft_strfdup.c\
		ft_strequ.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strjoin.c\
		ft_strffulljoin.c\
		ft_strffjoin.c\
		ft_strfsjoin.c\
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
		ft_recursive_npower.c \
		ft_putcolor.c \
		ft_check_char.c \
		ft_freedbtab.c \
		ft_freedbint.c \
		ft_putdbstr.c \
		ft_dbstrnew.c \
		ft_strfsub.c \
		ft_getchar.c \
		ft_strupcase.c \
		ft_lowercase.c \
		ft_swap.c \
		ft_strcapitalize.c \
		ft_strrev.c \
		ft_double_to_binary_converter.c \
		ft_convert_binary_to_hexa.c \
		ft_charrjoin.c \
		ft_charjoin.c \
		ft_remove_char_from_str.c \
		ft_remove_one_char_form_str.c \
		ft_nb_char_occur.c \
		ft_nb_char_occurs.c \
		ft_is_hexa.c \
		ft_get_rounder.c \
		ft_ftoa.c \
		get_next_line.c \
		ft_putdbint.c \
		ft_debug.c \
		ft_nb_nbr.c \
		ft_fabs.c \
		ft_fswap.c \
		ft_ipart_of_numb.c \
		ft_round.c \
		ft_fpart_of_numb.c \
		ft_rfpart_of_numb.c \
		ft_find_char.c \
		list_tools.c \
		parse_string.c \
		stock_for_parsing.c \
		parse_args.c \
		fix_impossible_flag.c \
		flag_plus_zero_aq.c \
		field.c \
		precision.c \
		length_modifier.c \
		transform_chain.c \
		final_display.c \
		length_modifier.c \
		transform_chain.c \
		final_display.c \
		ft_printf.c \
		flag_hash.c \
		ft_nb_char_occurs_c.c \
		ft_find_char_c.c \

HEADER = ./libft.h

all: $(NAME)

OBJECT = $(SRC:.c=.o)

#TEXT

		RM_OBJ = "\t\033[1;32mrm objects\t\t\033[1;32m[OK]\033[1m"
		RM_LIB = "\t\033[1;32mrm libft.a\t\t\033[1;32m[OK]\033[1m"
		COMPILING = "\t\033[1;34mlibft.a compilation\t\033[1;32m[OK]\033[1m"

$(NAME): $(OBJECT)
	@ar ruc $(NAME) $(OBJECT)
	@ranlib $(NAME)
	@echo $(COMPILING)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $(SRC) -I $<

clean:
	@rm -rf $(OBJECT)
	@echo $(RM_OBJ)

fclean: clean
	@rm -rf $(NAME)
	@echo $(RM_LIB)

re: fclean all

.PHONY: clean fclean
