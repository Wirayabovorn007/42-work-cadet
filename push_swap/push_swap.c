
#include "push_swap.h"

#include <stdio.h>
int	push_swap(int argc, char *argv[])
{
	Stack 	*a;
	Stack 	*b;
	int		max;

	if (has_err(argc, argv))
		return (1);
	max = argc - 1;
	if (argc == 2)
		max = get_size(argv[1]);
	a = initialize(max);
	b = initialize(max);
	if (!a || !b)
		return (1);
	assign_init(a, argc, argv);
	
	int *arr; //test
	int size = (argc == 2)? get_size(argv[1]):argc - 1;
	arr = a->arr;
	for (int i=0; i < size; i++)
		printf("%d\n", arr[i]);
	free(a->arr);
	free(a);
	free(b->arr);
	free(b);
	return (0);
}


