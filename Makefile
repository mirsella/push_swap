SRCS = push_swap.c parser.c pile.c
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -g3

LIBFT = libft/libft.a
NAME = push_swap

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):
	make -C libft

clean:
	make -C libft clean
	rm $(OBJS)

fclean: clean
	make -C libft fclean
	rm $(NAME)

re: fclean all

bonus: all

dev: all
	./$(NAME) $(ARGS)

.PHONY: all clean fclean re bonus
