# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/03 12:49:27 by loiberti     #+#   ##    ##    #+#        #
#    Updated: 2018/10/03 13:38:02 by loiberti    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libft.a
SRC = ./*.c
FlAG = -Wall -Wextra -Werror
OBJET = ./*.o

all: $(NAME)

$(NAME):
	@ gcc $(FLAG) -c -I ./ $(SRC)
	@ ar rc $(NAME) $(OBJET)

clean:
	@ /bin/rm -f $(OBJET)

fclean: clean
	@ /bin/rm -f $(NAME)

re: fclean all
