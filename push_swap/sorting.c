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
	int size_a;

	size_a = a->top + 1;
	while (size_a > 3)
	{
		min = get_min(a);
		while (a->arr[a->top] != min)
			ra(a);
		pb(a,b);
		size_a--;
	}

	sort_three(a);
	while (b->top != -1)
		pa(a, b);
}

// void	radix_sort(Stack *a, Stack *b)
// {
// 	int	i;
// 	int	j;
// 	int	num;
// 	int	size;
// 	int	max_bits;

// 	i = 0;
// 	size = a->top + 1;
// 	//max_bits = get_max_bits(size);
// 	while (i < max_bits)
// 	{
// 		j = 0;
// 		while (j < size)
// 		{
// 			num = a->arr[a->top];
// 			if (((num >> i) & 1) == 1)
// 				ra(a);
// 			else
// 				pb(a, b);
// 			j++;
// 		}
// 		while (b->top != -1)
// 			pa(a, b);
// 		i++;
// 	}
// }

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
	// else
	//  	radix_sort(a, b);
}
