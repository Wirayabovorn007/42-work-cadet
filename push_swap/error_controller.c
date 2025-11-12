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
			j = i + 1;
			while (j < get_size(argv[1]))
			{
				if (num_found[i] == num_found[j])
				{
					is_err = 1;
					break ;
				}
				j++;
			}
			if (is_err)
				break ;
			i++;
		}
	}
	else
	{
		while (i < argc)
		{
			j = 0;
			while (argv[i][j])
			{
				if (!(argv[i][j] >= '0' && argv[i][j] <= '9') && !(argv[i][j] == ' ') && !(argv[i][j] == '-')) // 1 2 3 one 4
				{
					write(2, "Error\n", 7);
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
	}
	if (is_err)
		write(2, "Error\n", 7);
	free(num_found);
	return (is_err);
}
