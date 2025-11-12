#include "push_swap.h"

void	sa(int *a)
{
	int	temp;

	temp = a[0];
	a[0] = a[1];
	a[1] = temp;
}

void	sb(int *b)
{
	int	temp;

	temp = b[0];
	b[0] = b[1];
	b[1] = temp;
}

void	ss(int *a, int *b)
{
	sa(a);
	sb(b);
}

void	rotate(Stack *st)
{
	int	*arr;
	int	last;
	int	i;

	//set last equal to first
	arr = st->arr;
	last = arr[st->ind];
	arr[st->ind] = arr[0];
	arr[st->ind - 1] = last;
	i = 1;
	while (i < st->ind - 1)
	{
		arr[i - 1] = arr[i];
	}
}

void	reverse_rotate(Stack *st)
{

}

void	pb(Stack *a, Stack *b)
{
	int	temp;

	temp = a->arr[0];
}

void	pa(Stack *a, Stack *b, int max)
{
	int	top_b;
	int	*arr_b;
	int	*arr_a;

	if (b->ind == -1 || b->top == -1 || is_full(a, max))
		return ;
	arr_b = b->arr;
	arr_a = a->arr;
	top_b = arr_b[0];
	arr_b[0] = NULL;
	push(top_b, a);
}