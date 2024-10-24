# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmachado <lmachado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/22 05:34:45 by lmachado          #+#    #+#              #
#    Updated: 2024/10/17 19:12:55 by lmachado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
FILES = src/cost.c src/main.c src/op_push.c src/op_rotate_reverse.c src/op_rotate.c src/op_swap.c src/stack.c src/target.c src/turk.c src/utils.c src/validate.c src/verify_str.c
OBJS = $(FILES:.c=.o)

NAME = push_swap

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

all:	$(LIBFT) $(NAME)

$(NAME):	$(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -I${LIBFT_DIR} -lft -L$(LIBFT_DIR) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)
	make bonus -C $(LIBFT_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean:	clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all