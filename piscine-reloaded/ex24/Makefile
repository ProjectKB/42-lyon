# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/01 17:17:26 by loiberti     #+#   ##    ##    #+#        #
#    Updated: 2018/10/01 17:19:15 by loiberti    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libft.a
SRC = ./srcs/ft_putchar.c \
	./srcs/ft_strcmp.c \
	./srcs/ft_strlen.c \
	./srcs/ft_swap.c \
	./srcs/ft_putstr.c
FlAG = -Wall -Wextra -Werror
OBJET = ./ft_putchar.o \
		./ft_strcmp.o \
		./ft_strlen.o \
		./ft_swap.o \
		./ft_putstr.o

all: $(NAME)

$(NAME):
	@ gcc $(FLAG) -c -I includes $(SRC)
	@ ar rc $(NAME) $(OBJET)

clean:
	@ /bin/rm -f $(OBJET)

fclean: clean
	@ /bin/rm -f $(NAME)

re: fclean all
