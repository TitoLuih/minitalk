NAME = minitalk
CC = cc
FLAGS = -Werror -Wextra -Wall

LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a

RM = rm -rf

SRC_CLIENT = src/client.c
SRC_SERVER = src/server.c

$(LIBFT):
	make -C $(LIBFT_PATH)

clean:
	$(RM) obj

fclean:
	$(RM) obj  $(NAME)

re: fclean all