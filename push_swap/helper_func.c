
#include "push_swap.h"

Stack	*initialize(int max)
{
	Stack	*st;

	st = malloc(sizeof(Stack));
	if (!st)
		return (NULL);
	st->arr = malloc(sizeof(int) * max);
	if (!st->arr)
	{
		free(st);
		return (NULL);
	}
	st->top = -1;
	st->ind = -1;
	return (st);
}

int	is_full(Stack *st, int max)
{
	return (st->ind == max);
}

void	push(int value, Stack *stack)
{
	int *arr;

	arr = stack->arr;
	arr[++stack->ind] = value;
	stack->top = 0;
}

int	is_found(int *arr, int val, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == val)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int 	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	assign_init(Stack *a, int argc, char *argv[])
{
	int	i;
	int	*arr;

	i = 1;
	while (i < argc)
	{
		push(ft_atoi(argv[i]), a);
		i++;
	}
}

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
