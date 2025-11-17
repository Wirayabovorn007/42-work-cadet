#include "../push_swap.h"

int	print_err()
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
	while (str[i])
	{
		if (num_found && space_found)
			return ((num_found >= 1) && space_found);
		if (str[i] >= '0' && str[i] <= '9')
			num_found++;
		if (str[i] == ' ')
			space_found = 1;
		i++;
	}
	return ((num_found >= 1) && space_found);
}

int	can_join_split(char *argv[])
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (can_split(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

long	ft_atol(char *str)
{
	int	i;
	int	sign;
	long	res;

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
	while (ft_isdigit(str[i]))
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * sign);
}
