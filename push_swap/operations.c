#include "push_swap.h"

void	swap(Stack *a)
{
	int	temp;

	if (a->top < 1)
		return ;
	temp = a->arr[a->top];
	a->arr[a->top] = a->arr[a->top - 1];
	a->arr[a->top - 1] = temp;
}

void	ss(Stack *a, Stack *b)
{
	swap(a);
	swap(b);
}

void	pa_pb(Stack *to_push, Stack *to_pop)
{
	int	temp_top;

	if (to_pop->top == -1)
		return ;
	temp_top = to_pop->arr[to_pop->top];
	to_pop->top--;
	push(temp_top, to_push);
}

void	rotate(Stack *st)
{
	int	i;
	int	temp_top;

	if (st->top < 1)
		return ;
	temp_top = st->arr[st->top];
	i = st->top;
	while (i > 0)
	{
		st->arr[i] = st->arr[i - 1];
		i--;
	}
	st->arr[0] = temp_top;
}

void	reverse_rotate(Stack *st)
{
	int	i;
	int	temp_bottom;

	if (st->top < 1)
		return ;
	temp_bottom = st->arr[0];
	i = 0;
	while (i < st->top)
	{
		st->arr[i] = st->arr[i + 1];
		i++;
	}
	st->arr[st->top] = temp_bottom;
}

void	rr(Stack *a, Stack *b)
{
	rotate(a);
	rotate(b);
}

void	rrr(Stack *a, Stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}