# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/24 14:13:06 by wiboonpr          #+#    #+#              #
#    Updated: 2025/11/24 14:13:07 by wiboonpr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror

SRC = $(wildcard main.c)
UTILS = $(wildcard utils/*.c)
CMDS = $(wildcard operations/*.c)

OBJS_SRC = $(SRC:%.c=%.o)
OBJS_UTILS = $(UTILS:%.c=%.o)
OBJS_CMDS = $(CMDS:%.c=%.o)
OBJS = $(OBJS_SRC) $(OBJS_UTILS) $(OBJS_CMDS)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
