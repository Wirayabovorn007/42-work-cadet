
#include "../push_swap.h"

void	rotate(Stack **stack)
{
	Stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = get_last_node(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}

void	ra(Stack **a)
{
	rotate(a);
	write(1, "ra\n", 4);
}
void	rb(Stack **b)
{
	rotate(b);
	write(1, "rb\n", 4);
}
void	rr(Stack **a, Stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 4);
}
