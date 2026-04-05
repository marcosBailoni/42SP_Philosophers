NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = parse_input.c \
	table_control.c \
	time_control.c \
	print_control.c \
	philosophers_routine.c \
	eat_sleep_rave_repeat.c \
	monitoring.c \
	philosophers.c	

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -lpthread -o $(NAME)

clean:
	rm -f $(OBJS)


fclean: clean
	rm -f $(NAME)

re: fclean all