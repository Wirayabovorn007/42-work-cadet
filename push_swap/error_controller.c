#include "push_swap.h"

int	has_err(int argc, char *argv[])
{
	int	i;
	int	j;
	int	is_err;
	int	*num_found;

	is_err = 0;
	if (argc < 2)
		is_err = 1;
	i = 1;
	while (i < argc)
	{
		j = 0;
		long long res = 0;
		int sign = 1;
		if (argv[i][j] == '+' || argv[i][j] == '-')
		{
			if (argv[i][j] == '-')
				sign = -1;
			j++;
		}
		if (argv[i][j] == '\0') 
		{
			write(2, "Error\n", 7);
			return (1);
		}
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
			{
				write(2, "Error\n", 7); // Error: non-digit
				return (1);
			}
			res = (res * 10) + (argv[i][j] - '0');
			if ((sign == 1 && res > 2147483647) || (sign == -1 && (res * sign) < -2147483648))
			{
				write(2, "Error\n", 7); // Error: overflow
				return (1);
			}
			j++;
		}
			i++;
		}
		i = 1;
		num_found = malloc(sizeof(int) * (argc - 1));
		if (!num_found)
		{
			write(2, "Error\n", 7);
			return (1);
		}
		while (i < argc)
		{
			if (is_found(num_found, ft_atoi(argv[i]), i - 1))
			{
				is_err = 1;
				// write(1, "Dulplicate\n", 12);
				break ;
			}
			num_found[i - 1] = ft_atoi(argv[i]);
			i++;
		}
		if (is_err)
			write(2, "Error\n", 7);
		free(num_found);
		return (is_err);
	}
