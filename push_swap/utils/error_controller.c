
#include "../push_swap.h"

int	is_duplicate(char *argv, char c, int curr)
{
	int	i;

	i = 0;
	while (i < curr)
	{
		if (argv[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	error_limit(char *argv)
{
	return ((ft_atol(argv) > 2147483647 || ft_atol(argv) < -2147483648));
}

int	has_err(char *argv[])
{
	int	j;
	int	i;
	char	c;

	i = 0;
	while (argv[i])
	{
		j = 0;
		c = argv[i][j];
		if (is_duplicate(argv[i], c, i) || error_limit(argv[i]))
			return (print_err());
		while (c)
		{
			if (!((c >= '0' && c <= '9') || c == '-' || c == '+'))
				return (print_err());
			j++;
		}
		i++;
	}
	return (0);
}
