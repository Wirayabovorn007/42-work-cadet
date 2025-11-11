
#include "push_swap.h"

int	has_err(int argc, char *argv[])
{
	int	i;
	int	is_err;
	int	*num_found;

	is_err = 0;
	if (argc < 2)
		is_err = 1;
	i = 1;
	if (argc == 2) //dulplicate number
	{
		i--;
		num_found = split_val(argv[1]);
		if (!num_found)
		{
			write(2, "Error\n", 7);
			return (1);
		}
		while (i < get_size(argv[1]))
		{
			if (is_found(num_found, num_found[i], get_size(argv[1])))
			{
				is_err = 1;
				break ;
			}
			num_found[i] = ft_atoi(argv[i]);
			i++;
		}
	}
	else
	{
		while (i < argc - 1)
		{
			if (!(argv[i] >= '0' && argv[i] <= '9') && !(argv[i] != ' ')) // 1 2 3 one 4
			{
				write(2, "Error\n", 7);
				return (1);
			}
		}
		i = 0;
		num_found = malloc(sizeof(int) * argc - 1);
		if (!num_found)
		{
			write(2, "Error\n", 7);
			return (1);
		}
		while (i < argc - 1)
		{
			if (is_found(num_found, ft_atoi(argv[i]), argc - 1))
			{
				is_err = 1;
				break ;
			}
			num_found[i] = ft_atoi(argv[i]);
			i++;
		}
	}
	if (is_err)
		write(2, "Error\n", 7);
	free(num_found);
	return (is_err);
}

#include <stdio.h>
int	push_swap(int argc, char *argv[])
{
	Stack 	*a;
	Stack 	*b;
	int		max;

	if (has_err(argc, argv))
		return (1);
	max = argc - 1;
	a = initialize(max);
	b = initialize(max);
	if (!a || !b)
		return (1);
	assign_init(a, argc, argv);
	
	// int *arr; //test
	// arr = a->arr;
	// for (int i=0; i < get_size(argv[1]); i++)
	// 	printf("%d\n", arr[i]);
	free(a->arr);
	free(a);
	free(b->arr);
	free(b);
	return (0);
}


