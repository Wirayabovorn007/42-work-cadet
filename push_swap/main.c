#include "push_swap.h"

int	push_swap(int argc, char *argv[])
{
	Stack	*a;
	Stack	*b;
	char	**args_to_process;
	int		must_free_args;	

	a = NULL;
	b = NULL;
	must_free_args = 0;
	if (argc < 2)
		return (0); 
	if (!argv[1][0])
		return (print_err());

	if (argc == 2 && can_split(argv[1]))
	{
		args_to_process = split_num(argv[1], ' ');
		must_free_args = 1;
	}
	else if (argc > 2 && can_join_split(argv + 1))
	{
		args_to_process = join_n_split(argv);
		must_free_args = 1;
	}
	else
	{
		args_to_process = argv + 1;
		must_free_args = 0;
	}

	if (has_err(args_to_process))
	{
		if (must_free_args)
			free_split_array(args_to_process);
		return (1);
	}

	init_stack(&a, args_to_process);

	if (must_free_args)
		free_split_array(args_to_process);

	if (!sorted(a))
		sort_stack(&a, &b);

	free_stack(&a);
	return (0);
}

int	main(int argc, char *argv[])
{
	return (push_swap(argc, argv));
}