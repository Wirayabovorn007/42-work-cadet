
#include "../push_swap.h"

void	push(Stack **src, Stack **dst)
{
	Stack	*to_be_pushed;

	if (!*src)
		return ;
	to_be_pushed = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	to_be_pushed->prev = NULL;
	if (!*dst)
	{
		*dst = to_be_pushed;
		to_be_pushed->next = NULL;
	}
	else
	{
		to_be_pushed->next = *dst;
		to_be_pushed->next->prev = to_be_pushed;
		*dst = to_be_pushed;
	}
}

void	pa(Stack **a, Stack **b)
{
	push(b, a); 
	write(1, "pa\n", 3);
}

void	pb(Stack **a, Stack **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}