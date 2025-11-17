NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror

SRC = $(wildcard srcs/*.c)
UTILS = $(wildcard utils/*.c)

OBJS_SRC = $(SRC:%.c=%.o)
OBJS_UTILS = $(UTILS:%.c=%.o)
OBJS = $(OBJS_SRC) $(OBJS_UTILS)

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
