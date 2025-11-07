
#include "push_swap.h"

int	has_err(int argc, char *argv[])
{
	if (argc < 2)
	{
		//printf("Error\n");
		return (1);
	}

	return (0);
}

int	push_swap(int argc, char *argv[])
{
	Stack 	*a;
	Stack 	*b;
	int		i;
	int		max;

	if (has_err(argc, argv))
		return (1);
	max = argc - 1;
	a = initialize(max);
	b = initialize(max);
	if (!a || !b)
		return (1);
	i = 1;
	while (i < argc)
	{
		push(ft_atoi(argv[i]), a, max);
		i++;
	}
	return (0);
}


