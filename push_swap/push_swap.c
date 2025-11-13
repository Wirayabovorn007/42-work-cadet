
#include "push_swap.h"

//#include <stdio.h> //test
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
	if (!is_sorted(a))
		sort_stack(a, b);

	
	
	
	// int *arr; //test
	// int size = a->top;
	// arr = a->arr;
	// while (size >= 0)
	// {
	// 	printf("%d\n", arr[size]);
	// 	size--;
	// }
	// printf("Top a : %d\n", arr[a->top]);




	free(a->arr);
	free(a);
	free(b->arr);
	free(b);
	return (0);
}

int	main(int argc, char *argv[])
{
	return (push_swap(argc, argv));
}

