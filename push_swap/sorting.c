#include "push_swap.h"

int	is_sorted(Stack *s)
{
	int	i;

	i = s->top;
	while (i > 0)
	{
		if (s->arr[i] > s->arr[i - 1])
			return (0);
		i--;
	}
	return (1);
}

void	sort_three(Stack *a)
{
	int	top;
	int	mid;
	int	bottom;

	top = a->arr[a->top];
	mid = a->arr[a->top - 1];
	bottom = a->arr[0];
	if (top > mid && top > bottom)
		ra(a);
	else if (mid > top && mid > bottom)
		rra(a);
	top = a->arr[a->top];
	mid = a->arr[a->top - 1];
	if (top > mid)
		sa(a);
}

int	get_min(Stack *a)
{
	int	i;
	int	min;

	i = a->top;
	min = a->arr[i];
	while (i >= 0)
	{
		if (a->arr[i] < min)
			min = a->arr[i];
		i--;
	}
	return (min);
}

int	get_min_index(Stack *a, int min)
{
	int	i;

	i = a->top;
	while (i >= 0)
	{
		if (a->arr[i] == min)
			return (i);
		i--;
	}
	return (-1);
}

void	sort_four_five(Stack *a, Stack *b)
{
	int min;
	int	min_ind;
	int size_a;

	size_a = a->top + 1;
	while (size_a > 3)
	{
		min = get_min(a);
		min_ind = get_min_index(a, min);
		if (min_ind <= a->top / 2)
			while (a->arr[a->top] != min)
				rra(a);
		else
			while (a->arr[a->top] != min)
				ra(a);
		pb(a,b);
		size_a--;
	}
	sort_three(a);
	while (b->top != -1)
		pa(a, b);
}

void	move_smallest_to_top(Stack *a)
{
	int min;
	int size_a;

	size_a = a->top + 1;
	while (size_a >= 0)
	{
		min = get_min(a);
		while (a->arr[a->top] != min)
			ra(a);
		size_a--;
	}
}

void	big_sort(Stack *a, Stack *b)
{
	int	len_a;

	len_a = a->top + 1;
	while (len_a-- > 3)
	{
		move_smallest_to_top(a);
		pb(a, b);
	}
	sort_three(a);
	while (b->top != -1)
		pa(a, b);
}

void	sort_stack(Stack *a, Stack *b)
{
	int	length;
	int	len_a;

	len_a = 0;
	length = a->top;
	while (length >= 0)
	{
		length--;
		len_a++;
	}
	if (len_a == 2)
	{
		if (a->arr[a->top] > a->arr[a->top - 1])
			sa(a);
	}
	else if (len_a == 3)
		sort_three(a);
	else if (len_a <= 5)
		sort_four_five(a, b);
	else
		big_sort(a, b);
}
