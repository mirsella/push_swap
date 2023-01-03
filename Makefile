SHARED_SRCS = $(addprefix shared_srcs/, pile.c pile_action_basic.c pile_action_rotate.c parser.c)

SRCS = $(addprefix push_swap_srcs/, push_swap.c sort.c sort_algo.c sort_algo_advanced.c) $(SHARED_SRCS)
OBJS = $(SRCS:.c=.o)

BSRCS = $(addprefix checker_srcs/, checker.c) $(SHARED_SRCS)
BOBJS = $(BSRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a
BNAME = checker
NAME = push_swap

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

clean:
	make -C libft clean
	rm $(OBJS) $(BOBJS)

fclean: clean
	rm $(NAME) $(BNAME) $(LIBFT)

re: fclean all

bonus: $(LIBFT) $(BOBJS)
	$(CC) $(CFLAGS) -o $(BNAME) $(BOBJS) $(LIBFT)

$(LIBFT):
	make -C libft

dev: all
	./$(NAME) $(ARGS)

.PHONY: all clean fclean re bonus dev
