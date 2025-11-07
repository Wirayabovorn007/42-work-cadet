#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stdlib.h>

typedef struct Stack
{
	int	*arr;
	int	top;
}	Stack;

Stack	*initialize(Stack *stack, int max);
void	push(int value, Stack *stack, int max);
int	ft_atoi(const char *str);

#endif