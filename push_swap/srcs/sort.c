
#include "../push_swap.h"

int	sorted(Stack *a)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

void	sort_three(Stack **a)
{
	Stack	*biggest;

	biggest = get_max(*a);
	if (biggest == *a)
		ra(a);
	else if ((*a)->next == biggest)
		rra(a);
	if ((*a)->value > (*a)->next->value) //bottom is biggest
		sa(a);
}

void	sort_big_stack(Stack **a, Stack **b)
{
	int	len_a;

	len_a = len_stack(*a);
	if (len_a-- > 3 && !sorted(*a))
		pb(a, b);
	if (len_a-- > 3 && !sorted(*a))
		pb(a, b);
	while (len_a-- > 3 && !sorted(*a))
	{
		initiate_a(*a, *b);
	}
}

void	sort_stack(Stack** a, Stack **b)
{
	if (len_stack(*a) == 2)
		sa(&a);
	else if (len_stack(*a) == 3)
		sort_three(&a);
	else
		sort_big_stack(&a, &b);
}
