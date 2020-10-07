NAME = ft_ssl

LIB = libft/libft.a

INCLUDE = -I includes -I libft/includes

CC = gcc

SRC =	shared/main.c \
		md5/utils.c \
		md5/md5.c \
		sha256/sha256.c \
		sha256/utils.c \
		shared/shared.c \

OBJ = $(SRC:.c=.o)

HEADER = md5.h sha256.h shared.h

DSRC = srcs/
DOBJ = obj/
DHEADER = includes/

SUB_DOBJ = $(addprefix $(DOBJ),shared) $(addprefix $(DOBJ),md5) $(addprefix $(DOBJ),sha256)

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

$(DOBJ)%.o : $(DSRC)%.c $(CHEADER)
	@$(eval COUNT = 0)
	@mkdir -p $(DOBJ) $(SUB_DOBJ)
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