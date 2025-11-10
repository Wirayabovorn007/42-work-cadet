#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stdlib.h>

typedef struct Stack
{
	int	*arr;
	int	top;
}	Stack;

int		push_swap(int argc, char *argv[]);
void	assign_init(Stack *a, int argc, char *argv[]);
Stack	*initialize(int max);
int		has_err(int argc, char *argv[]);
void	push(int value, Stack *stack);
int		get_size(char *str);
int		ft_atoi(const char *str);

#endif