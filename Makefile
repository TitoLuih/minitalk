NAME_SERVER = server
NAME_CLIENT = client

NAME_BONUS = server_bonus
NAME_C_BONUS = client_bonus

CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
LIBFT_PATH = libft
LIBFT_A = $(LIBFT_PATH)/libft.a

SRC_SERVER = src/server.c
SRC_CLIENT = src/client.c
SRC_SERVER_BONUS = src_bonus/server_bonus.c
SRC_CLIENT_BONUS = src_bonus/client_bonus.c

all: $(LIBFT_A) server client

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_PATH)

server: $(LIBFT_A) $(SRC_SERVER)
	@cc $(CFLAGS) -o $(NAME_SERVER) $(SRC_SERVER) $(LIBFT_A)
	@echo "Server executable created"

client: $(LIBFT_A) $(SRC_CLIENT)
	@cc $(CFLAGS) -o $(NAME_CLIENT) $(SRC_CLIENT) $(LIBFT_A)
	@echo "Client executable created"

clean:
	@$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

.PHONY: all bonus clean fclean re