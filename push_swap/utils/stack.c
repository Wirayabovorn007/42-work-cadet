#include "../push_swap.h"

Stack* get_last_node(Stack *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

int	len_stack(Stack *a)
{
	int	i;

	if (!a)
		return (0);
	i = 0;
	while (a)
	{
		a = a->next;
		i++;
	}
	return (i);
}

void	append(Stack **st, int val)
{
	Stack	*node;
	Stack	*last_node;

	if (!st)
		return ;
	node = malloc(sizeof(Stack));
	if (!node)
		return ;
	node->next = NULL;
	node->value = val;
	node->index = 0;
	node->is_cheapest = 0;
	node->is_above_median = 0;
	if (!(*st))
	{
		*st = node;
		node->prev = NULL;
	}
	else
	{
		last_node = get_last_node(*st);
		last_node->next = node;
		node->prev = last_node;
	}
}

int	init_stack(Stack **a, char *argv[])
{
	int		i;

	i = 0;
	while (argv[i])
	{
		append(a, (int)ft_atol(argv[i]));
		i++;
	}
	return (0);
}

Stack	*get_max(Stack *stack)
{
	long	max;
	Stack	*maxnode;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->value > max)
		{
			max = stack->value;
			maxnode = stack;
		}
		stack = stack->next;
	}
	return (maxnode);
}

Stack	*get_min(Stack *stack)
{
	long	min;
	Stack	*minnode;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			minnode = stack;
		}
		stack = stack->next;
	}
	return (minnode);
}

void	update_index(Stack *stack)
{
	int	i;
	int	median;

	if (!stack)
		return ;
	i = 0;
	median = len_stack(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->is_above_median = 1;
		else
			stack->is_above_median = 0;
		stack = stack->next;
		i++;
	}
}

void	set_target_a(Stack *a, Stack *b)
{
	Stack	*curr_b;
	Stack	*target;
	long	bestmatch;

	while (a)
	{
		bestmatch = LONG_MIN;
		curr_b = b;
		while (curr_b)
		{
			if (curr_b->value < a->value && curr_b->value > bestmatch)
			{
				bestmatch = curr_b->value;
				target = curr_b;
			}
			curr_b = curr_b->next;
		}
		if (bestmatch == LONG_MIN)
			a->target = get_max(b);
		else
			a->target = target;
		a = a->next;
	}
}
void	set_target_b(Stack *a, Stack *b)
{
	Stack	*curr_a;
	Stack	*target;
	long	bestmatch;

	while (b)
	{
		bestmatch = LONG_MAX;
		curr_a = a;
		while (curr_a)
		{
			if (curr_a->value > b->value && curr_a->value < bestmatch)
			{
				bestmatch = curr_a->value;
				target = curr_a;
			}
			curr_a = curr_a->next;
		}
		if (bestmatch == LONG_MAX)
			b->target = get_min(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	calculate_push_cost_a(Stack *a, Stack *b)
{
	int	len_a;
	int	len_b;

	len_a = len_stack(a);
	len_b = len_stack(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->is_above_median))
			a->push_cost = len_a - (a->index);
		if (a->target)
		{
			if (a->target->is_above_median)
				a->push_cost += a->target->index;
			else
				a->push_cost += len_b - (a->target->index);
		}
		a = a->next;
	}
}

void	set_is_cheapest(Stack	*stack)
{
	long	cheapest_val;
	Stack*	cheapest_node;
	Stack*	curr;

	if (!stack)
		return ;
	curr = stack;
	while (curr)
	{
		curr->is_cheapest = 0;
		curr = curr->next;
	}
	cheapest_node = NULL;
	cheapest_val = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_val)
		{
			cheapest_val = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	if (cheapest_node)
		cheapest_node->is_cheapest = 1;
}

void	update_a(Stack *a, Stack *b)
{
	update_index(a);
	update_index(b);
	set_target_a(a, b);
	calculate_push_cost_a(a, b);
	set_is_cheapest(a);
}

void	update_b(Stack *a, Stack *b)
{
	update_index(a);
	update_index(b);
	set_target_b(a, b);
}

Stack	*get_cheapest(Stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->is_cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	rotate_with_cheap(Stack **a, Stack **b, Stack *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		rr(a, b);
	update_index(*a);
	update_index(*b);
}

void	rev_rotate_with_cheap(Stack **a, Stack **b, Stack *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		rrr(a, b);
	update_index(*a);
	update_index(*b);
}

void	required_node_to_top(Stack **stack, Stack *top, char st)
{
	while (*stack != top)
	{
		if (st == 'a')
		{
			if (top->is_above_median)
				ra(stack);
			else
				rra(stack);
		}
		if (st == 'b')
		{
			if (top->is_above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	move_cheapest_a_to_b(Stack **a, Stack **b)
{
	Stack	*cheapest;

	cheapest = get_cheapest(*a);
	if (!cheapest)
		return ;
	if (cheapest->is_above_median && cheapest->target->is_above_median)
		rotate_with_cheap(a, b, cheapest);
	else if (!(cheapest->is_above_median) && !(cheapest->target->is_above_median))
		rev_rotate_with_cheap(a, b, cheapest);
	required_node_to_top(a, cheapest, 'a');
	required_node_to_top(b, cheapest->target, 'b');
	pb(a, b);
}

void	move_cheapest_b_to_a(Stack **a, Stack **b)
{
	if (!b)
		return ;
	required_node_to_top(a, (*b)->target, 'a');
	pa(a, b);
}