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
	write(1, "ss\n", 4);
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
	write(1, "rr\n", 4);
}

void	rrr(Stack *a, Stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n",5);
}

void	sa(Stack *a)
{
	swap(a);
	write(1, "sa\n", 4);
}

void	sb(Stack *b)
{
	swap(b);
	write(1, "sb\n", 4);
}

void	pa(Stack *a, Stack *b)
{
	pa_pb(a, b);
	write(1, "pa\n", 4);
}

void	pb(Stack *a, Stack *b)
{
	pa_pb(b, a);
	write(1, "pb\n", 4);
}

void	ra(Stack *a)
{
	rotate(a);
	write(1, "ra\n", 4);
}

void	rb(Stack *b)
{
	rotate(b);
	write(1, "rb\n", 4);
}

void	rra(Stack *a)
{
	reverse_rotate(a);
	write(1, "rra\n", 5);
}

void	rrb(Stack *b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 5);
}