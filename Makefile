SRCS = $(addprefix push_swap_srcs/, push_swap.c sort.c sort_algo.c) \
	   $(addprefix shared_srcs/, pile.c pile_action_basic.c pile_action_rotate.c parser.c)
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
# CFLAGS += -g3

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
	rm $(NAME) $(LIBFT)

re: fclean all

bonus: all

dev: all
	./$(NAME) $(ARGS)

.PHONY: all clean fclean re bonus
