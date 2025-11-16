NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror


SRC = $(wildcard *.c)
OBJS = $(SRC:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean : 
	rm -f $(OBJS)

fclean :
	rm -f $(OBJS)
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
