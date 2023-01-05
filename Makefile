SHARED_SRCS = $(addprefix shared_srcs/, pile.c pile_action_basic.c pile_action_rotate.c parser.c)
SHARED_OBJS = $(SHARED_SRCS:.c=.o)

SRCS = $(addprefix push_swap_srcs/, push_swap.c sort.c sort_algo.c sort_algo_advanced_patopb.c sort_algo_advanced_pbtopa.c)
OBJS = $(SRCS:.c=.o)

BSRCS = $(addprefix checker_srcs/, checker.c)
BOBJS = $(BSRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a
BNAME = checker
NAME = push_swap

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) $(SHARED_OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(SHARED_OBJS) $(LIBFT)

clean:
	make -C libft clean
	rm -f $(OBJS) $(BOBJS) $(SHARED_OBJS)

fclean: clean
	rm -f $(NAME) $(BNAME) $(LIBFT)

re: fclean all

bonus: $(LIBFT) $(BOBJS) $(SHARED_OBJS)
	$(CC) $(CFLAGS) -o $(BNAME) $(BOBJS) $(SHARED_OBJS) $(LIBFT)

$(LIBFT):
	make -C libft

dev: all
	./$(NAME) $(ARGS)

.PHONY: all clean fclean re bonus dev
