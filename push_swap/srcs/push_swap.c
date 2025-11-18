#include "../push_swap.h"

int	push_swap(int argc, char *argv[])
{
	Stack	*a;
	Stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2 || !argv[1][0])
		return (1);
	if (argc == 2 && can_split(argv[1])) //./push_swap "1 -2 3 4 -5"
		argv = split_num(argv[1], ' ');
	if (argc >= 2 && can_join_split(argv)) //./push_swap "1 -2" 3 "4 -5"
		argv = join_n_split(argv);
	if (has_err(argv + 1))
		return (1);
	init_stack(&a, argv + 1);
	if (!sorted(a))
		sort_stack(&a, &b);
	free_stack(&a);
	return (0);
}

int	main(int argc, char *argv[])
{
	return (push_swap(argc, argv));
}