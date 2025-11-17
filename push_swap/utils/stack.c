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

void	append(Stack **st, int val, int ind)
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
	node->index= ind;
	node->is_cheapest = 0;
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
	long	n;
	int		i;

	i = 0;
	if (has_err(argv))
		return (1);
	while (argv[i])
	{
		append(a, (int)ft_atol(argv[i]), i);
		i++;
	}
	return (0);
}

Stack	*get_max(Stack *stack)
{
	int		max;
	Stack	*maxnode;

	if (!stack)
		return (NULL);
	max = stack->value;
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

void	set_is_above_median(Stack *stack)
{
	int	median;

	if (!stack)
		return ;
	median = len_stack(stack) / 2;
	while (stack)
	{
		if (stack->index <= median)
			stack->is_above_median = 1;
		else
			stack->is_above_median = 0;
		stack = stack->next;
	}
}

void	set_target(Stack *a, Stack *b)
{
	
}

void	initiate_a(Stack *a, Stack *b)
{
	set_is_above_median(a);
	set_is_above_median(b);
}