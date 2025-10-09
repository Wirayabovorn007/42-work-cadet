# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wiraya <wiraya@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/07 12:58:47 by wiboonpr          #+#    #+#              #
#    Updated: 2025/10/09 10:25:54 by wiraya           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Wextra -Weror

AR = ar rcs

SRC = $(wildcard *.c)
OBJS = $(SRC:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus : all

clean : 
	rm -f $(OBJS)

fclean :
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus