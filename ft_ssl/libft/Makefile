# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: loiberti <loiberti@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/14 18:49:50 by loiberti          #+#    #+#              #
#    Updated: 2020/12/14 11:55:58 by loiberti         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC= gcc

CFLAGS= -Wall -Wextra -g

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
		ft_ustrcmp.c\
		ft_strcpy.c\
		ft_ustrcpy.c\
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
		ft_charcolor.c \
		ft_check_char.c \
		ft_freedbtab.c \
		ft_freedbint.c \
		ft_putdbtab.c \
		ft_strjoin2.c \
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
		ft_realloc.c \
		ft_random.c \
		ft_ustrncat.c \
		ft_hexstr.c \
		ft_print_bits.c \
		ft_print_bits_to_hexa.c \
		ft_hexatoi.c \
		ft_str_to_uint64.c \
		ft_uint64_to_str.c \
		ft_ustrncmp.c \
		ft_strip_str.c \
		ft_strip_whitespaces.c \
		ft_putnstr.c \
		ft_putstrnchar.c \

OBJ = $(SRC:.c=.o)

HEADER = libft.h

COUNT = 1

all: $(NAME)
	@if [ $(COUNT) = 1 ]; then \
		echo "\033[1;34mNothing are changed !\033[0m"; \
	fi

$(NAME): $(OBJ)
	@ar ruc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[JCompilation\033[38;5;326m completed\033[0m"
	@echo "Compilation \033[34m"$(NAME)"\033[0m"

%.o: %.c $(HEADER)
	@$(eval COUNT = 0)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compilation from fonction \033[38;5;326m"$< "\033[0m\033[K\033[1A"

clean:
	@rm -rf $(OBJ)
	@echo "Deleting \033[38;5;265mlibft objects\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "Deleting \033[38;5;265m"$(NAME) "\033[0m"

re: fclean all

.PHONY: clean fclean
