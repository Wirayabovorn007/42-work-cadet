#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stdlib.h>
#include <unistd.h>

typedef struct Stack
{
	int	*arr;
	int	top;
}	Stack;

int		push_swap(int argc, char *argv[]);
int		is_full(Stack *st, int max);
void	assign_init(Stack *a, int argc, char *argv[]);
Stack	*initialize(int max);
int		has_err(int argc, char *argv[]);
int		is_found(int *arr, int val, int size);
void	push(int value, Stack *stack);
int		ft_atoi(const char *str);
void	swap(Stack *a);
void	ss(Stack *a, Stack *b);
void	pa_pb(Stack *to_push, Stack *to_pop);
void	rotate(Stack *st);
void	reverse_rotate(Stack *st);
void	rr(Stack *a, Stack *b);
void	rrr(Stack *a, Stack *b);

#endif