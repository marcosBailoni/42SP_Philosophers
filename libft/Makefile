# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcos <marcos@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/25 15:28:39 by maralves          #+#    #+#              #
#    Updated: 2025/11/27 10:39:27 by marcos           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_memchr.c \
      ft_strchr.c \
      ft_strrchr.c \
      ft_atoi.c \
      ft_memcmp.c \
      ft_strdup.c \
      ft_strtrim.c \
      ft_bzero.c \
      ft_memcpy.c \
      ft_striteri.c \
      ft_substr.c \
      ft_calloc.c \
      ft_memmove.c \
      ft_strjoin.c \
      ft_tolower.c \
      ft_isalnum.c \
      ft_memset.c \
      ft_strlcat.c \
      ft_toupper.c \
      ft_isalpha.c \
      ft_putchar_fd.c \
      ft_putchar.c \
      ft_strlcpy.c \
      ft_isdigit.c \
      ft_putnbr_fd.c \
      ft_strmapi.c \
      ft_isprint.c \
      ft_putstr_fd.c \
      ft_putstr.c \
      ft_strncmp.c \
      ft_itoa.c \
      ft_atoll.c \
      ft_split.c \
      ft_strnstr.c\
	ft_isascii.c\
	ft_strlen.c\
      ft_putendl_fd.c

BONUS_SRC = ft_lstnew_bonus.c\
      ft_lstadd_front_bonus.c\
      ft_lstsize_bonus.c\
      ft_lstlast_bonus.c\
      ft_lstadd_back_bonus.c\
      ft_lstdelone_bonus.c\
      ft_lstclear_bonus.c\
      ft_lstiter_bonus.c\
      ft_lstmap_bonus.c

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME) .bonus_built

.bonus_built: $(BONUS_OBJ)
	ar rcs $(NAME) $(BONUS_OBJ)
	touch .bonus_built

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
