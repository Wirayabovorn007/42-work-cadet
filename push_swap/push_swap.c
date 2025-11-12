
#include "push_swap.h"

#include <stdio.h> //test
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
	//sort(a, b);
	int *arr; //test
	int size = argc - 1;
	arr = a->arr;
	for (int i=0; i < size; i++)
		printf("%d\n", arr[i]);
	printf("Top a : %d\n", arr[a->top]);
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

