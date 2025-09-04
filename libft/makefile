NAME = libft.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRC = $(wildcard *.c)


OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o:%.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re