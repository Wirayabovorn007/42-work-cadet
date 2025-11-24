/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:10:42 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/11/24 14:10:45 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

void	smallest_to_top(Stack **a)
{
	Stack	*min;

	min = get_min(*a);
	while (*a != min)
	{
		if (min->is_above_median)
			ra(a);
		else
			rra(a);
	}
}

void	sort_big_stack(Stack **a, Stack **b)
{
	int	len_a;

	len_a = len_stack(*a);
	if (len_a-- > 3 && !sorted(*a))
		pb(a, b);
	if (len_a-- > 3 && !sorted(*a))
		pb(a, b);
	if (*b && (*b)->next && (*b)->value < (*b)->next->value)
		sb(b);
	while (len_a-- > 3 && !sorted(*a))
	{
		update_a(*a, *b);
		move_cheapest_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		update_b(*a, *b);
		move_cheapest_b_to_a(a, b);
	}
	update_index(*a);
	smallest_to_top(a);
}

void	sort_stack(Stack** a, Stack **b)
{
	if (len_stack(*a) == 2)
		sa(a);
	else if (len_stack(*a) == 3)
		sort_three(a);
	else
		sort_big_stack(a, b);
}
