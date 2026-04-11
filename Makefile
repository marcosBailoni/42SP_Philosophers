NAME = philosophers

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = parse_input.c \
	table_control.c \
	time_control.c \
	print_control.c \
	philosophers_routine.c \
	eat_sleep_rave_repeat.c \
	monitoring.c \
	aux_functions.c \
	philosophers.c	

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -lpthread -o $(NAME)	

clean:
	rm -f $(OBJS)


fclean: clean
	rm -f $(NAME)

re: fclean all