#include "../push_swap.h"

void	reverse_rotate(Stack **stack)
{
	Stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = get_last_node(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra(Stack **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 5);
}

void	rrb(Stack **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 5);
}

void	rrr(Stack **a, Stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 5);
}