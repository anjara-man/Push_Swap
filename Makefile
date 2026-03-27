# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anjaraan <anjaraan@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/06 15:44:06 by anjaraan          #+#    #+#              #
#    Updated: 2026/03/24 11:29:01 by anjaraan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIB_DIR = libft/

LIB_NAME = $(LIB_DIR)/libft.a

SRC = push_functions.c parsing_function.c simple_strategy.c bubble_sort_strategy.c\
		is_sorted.c disorder_metric.c reverse_rotate_functions.c rotate_functions.c swap_functions.c\
		stack_utils.c parsing_utils.c main.c print_error.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIB_NAME):
	$(MAKE) -C $(LIB_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(LIB_DIR)

$(NAME): $(OBJ) $(LIB_NAME)
	$(CC) $(CFLAGS) $(OBJ) -L $(LIB_DIR) -lft -o $(NAME)

clean:
	$(MAKE) clean -C $(LIB_DIR)
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C $(LIB_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re