NAME = ft_display_file

SRC = srcs/*.c

FLAG = -Wall -Werror -Wextra

OBJ = *.o

HEAD = ./includes

all: $(NAME)

$(NAME): $(OBJ)
	    gcc -o $(NAME) $(OBJ) -I $(HEAD)

$(OBJ):
	    gcc -c $(FLAG) $(SRC) -I$(HEAD)

clean:
	    rm -f *.o

fclean: clean
	    rm -f $(NAME)

re: fclean all
