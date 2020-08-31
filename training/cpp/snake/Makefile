# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/06/07 13:02:13 by loiberti     #+#   ##    ##    #+#        #
#    Updated: 2019/12/09 18:31:01 by loiberti    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #
# **************************************************************************** #

NAME = snake

LIB = -lncurses

INCLUDE = -I includes

CC = ~/.brew/bin/g++-10

SRC =	main.cpp \
		Window.cpp \
		Snake.cpp \

OBJ = $(SRC:.cpp=.o)

HEADER = Snake.hpp \
		 Window.hpp \

DSRC = srcs/
DOBJ = obj/
DHEADER = includes/

CSRC = $(addprefix $(DSRC),$(SRC))
COBJ = $(addprefix $(DOBJ),$(OBJ))
CHEADER = $(addprefix $(DHEADER),$(HEADER))

COUNT = 1

all: $(NAME)
	@if [ $(COUNT) = 1 ]; then \
		echo "\033[1;34mNothing are changed !\033[0m"; \
	fi

$(NAME): $(COBJ)
	@echo "\033[JCompilation\033[38;5;326m completed\033[0m"
	@echo "Compilation \033[34m"$(NAME)"\033[0m"
	@$(CC) $(COBJ) $(LIB) -o $(NAME)

$(DOBJ)%.o : $(DSRC)%.cpp $(CHEADER)
	@$(eval COUNT = 0)
	@mkdir -p $(DOBJ)
	@$(CC) $(INCLUDE) -c $< -o $@
	@echo "Compilation from fonction \033[38;5;326m"$< "\033[0m\033[K\033[1A"

clean:
	@rm -rf $(DOBJ)
	@echo "Deleting \033[38;5;265mobjects\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "Deleting \033[38;5;265m"$(NAME) "\033[0m"

re:
	@rm -f $(NAME)
	@rm -rf $(DOBJ)
	@echo "Deleting \033[38;5;265m"$(NAME) "\033[0m"
	@echo "Deleting \033[38;5;265mobjects\033[0m"
	@make all

.PHONY: default all fclean clean re
