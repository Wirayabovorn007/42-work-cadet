#include "../push_swap.h"

int	print_err(void)
{
	write(2, "Error\n", 7);
	return (1);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	can_split(char *str)
{
	int	i;
	int	num_found;
	int	space_found;

	i = 0;
	num_found = 0;
	space_found = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		// This check is a bit off, but it's not the main bug
		// A better check would be to just look for a space
		if (str[i] >= '0' && str[i] <= '9')
			num_found = 1;
		if (str[i] == ' ')
			space_found = 1;
		i++;
	}
	return (num_found && space_found);
}

int	can_join_split(char *argv[])
{
	int	i;

	if (!argv)
		return (0);
	i = 0; // Should start at 1 to skip program name
	while (argv[i])
	{
		if (can_split(argv[i]))
			return (1);
		i++;
	}
	return (0);
}
