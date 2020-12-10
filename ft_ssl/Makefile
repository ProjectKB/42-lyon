NAME = ft_ssl

LIB = libft/libft.a

INCLUDE = -I includes -I libft/

CC = gcc

CFLAGS= -Wall -Wextra -Werror

SRC = shared/main.c \
	  shared/shared.c \
	  shared/globals.c \
	  shared/errors.c \
	  shared/tools.c \
	  message_digest/md5/tools.c \
	  message_digest/md5/md5.c \
	  message_digest/md5/globals.c \
	  message_digest/sha256/sha256.c \
	  message_digest/sha256/tools1.c \
	  message_digest/sha256/tools2.c \
	  message_digest/sha256/globals.c \
	  message_digest/shared/print.c \
	  message_digest/shared/pre_process.c \
	  message_digest/shared/errors.c \
	  base64/encode.c \
	  base64/decode.c \
	  base64/base64.c \
	  base64/globals.c \
	  base64/print.c \
	  base64/pre_process.c \
	  base64/errors.c \
	  cipher_block/globals.c \
	  cipher_block/tools.c \
	  cipher_block/des.c \
	  cipher_block/print.c \
	  cipher_block/pre_process.c \
	  cipher_block/errors.c \
	  cipher_block/keys.c \
	  cipher_block/flags_action1.c \
	  cipher_block/flags_action2.c \
	  cipher_block/pbkdf.c \

OBJ = $(SRC:.c=.o)

HEADER = ft_ssl.h

DSRC = srcs/
DOBJ = obj/
DHEADER = includes/

SUB_DOBJ = $(addprefix $(DOBJ),shared) \
		   $(addprefix $(DOBJ),message_digest/md5) \
		   $(addprefix $(DOBJ),message_digest/sha256) \
		   $(addprefix $(DOBJ),message_digest/shared) \
		   $(addprefix $(DOBJ),base64) \
		   $(addprefix $(DOBJ),cipher_block/shared) \

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
	@$(CC) $(CFLAGS) $(COBJ) $(LIB) -o $(NAME)

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