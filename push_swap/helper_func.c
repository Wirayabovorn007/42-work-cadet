/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 21:18:53 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/11/07 21:47:32 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

Stack	*initialize(Stack *stack, int max)
{
	Stack	*st;
	int	*arr;

	st = stack;
	arr = st->arr;
	arr = malloc(sizeof(int) * max);
	if (!arr)
		return (NULL);
	st->top = -1;
	return (st);
}

// int	is_full(Stack *st, int max)
// {
// 	return (st->top == max);
// }

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

void	push(int value, Stack *stack, int max)
{
	int *arr;

	arr = stack->arr;
	arr[++stack->top] = value;
}