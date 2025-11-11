
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
	return (st);
}

// int	is_full(Stack *st, int max)
// {
// 	return (st->top == max);
// }

void	push(int value, Stack *stack)
{
	int *arr;

	arr = stack->arr;
	arr[++stack->top] = value;
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

int	check_argv(char *argv[])
{
	int	i;
	int	num_found;
	int	space_found;
	char	c;

	i = 0;
	num_found = 0;
	space_found = 0;
	while (argv[1][i])
	{
		c = argv[1][i];
		if (num_found && space_found)
			return (num_found && space_found);
		if (c == ' ')
			space_found = 1;
		if (c <= '9' && c >= '0')
			num_found = 1;
		i++;
	}
	return (num_found && space_found);
}

int	get_size(char *str)
{
	int	i;
	int	in_num;
	int	count;

	i = 0;
	in_num = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			if (in_num == 0)
			{
				count++;
				in_num = 1;
			}
		}
		else
			in_num = 0;
		i++;
	}
	return (count);
}

int	ft_strlen(char *str)
{
	int 	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
//#include <stdio.h>
int*	split_val(char *argv) // "-1 -2 -3" didn't handle this case yet
{
	int	tmp;
	int	*arr;
	int	i;
	int	j;
	int	n;
	int	in_num;

	//printf("Size: %d\n", get_size(argv));
	i = 0;
	while (i < ft_strlen(argv))
		if (!(argv[i] >= '0' && argv[i] <= '9') && !(argv[i] != ' ')) // "1 2 3 one 4"
			return (NULL);
	arr = malloc(get_size(argv) * sizeof(int));
	if (!arr)
		return (NULL);
	i = 0;
	tmp = 0;
	j = 0;
	n = 1;
	in_num = 0;
	while (argv[j])
	{
		if (argv[j] == '-')
			n = -1;
		if (argv[j] >= '0' && argv[j] <= '9')
		{
			tmp = ((tmp * 10) + (argv[j] - '0')) * n;
			in_num = 1;
		}
		else if (in_num == 1)
		{
			arr[i] = tmp;
		//	printf("arr[i]: %d\n", arr[i]);
			tmp = 0;
			in_num = 0;
			i++;
		}
		j++;
	}
	if (in_num == 1)
		arr[i] = tmp;
	// printf("arr[i]: %d\n", arr[i]);
	return (arr);
}

void	assign_init(Stack *a, int argc, char *argv[])
{
	int	i;
	int	*arr;

	i = 1;
	if (argc == 2 && check_argv(argv))
	{
		arr = split_val(argv[1]);
		if (!arr)
			return ;
		i--;
		while (i < get_size(argv[1]))
		{
			push(arr[i], a);
			i++;
		}
		free(arr);
		return ;
	}
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
