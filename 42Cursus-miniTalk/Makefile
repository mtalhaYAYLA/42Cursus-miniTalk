NAME = libft.a
LIBFT = Libft

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(NAME)
	$(CC) $(CFLAGS) server.c $(NAME) -o server
	$(CC) $(CFLAGS) client.c $(NAME) -o client

$(NAME): $(LIBFT)
	make -C $(LIBFT)
	cp Libft/libft.a .

clean:
	make clean -C $(LIBFT)

fclean: clean
	make fclean -C $(LIBFT)
	$(RM) $(NAME)
	$(RM) server.o client.o

re: fclean all

.PHONY: clean fclean all