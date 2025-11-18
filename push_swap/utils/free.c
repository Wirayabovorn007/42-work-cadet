
#include "../push_swap.h"

void	free_stack(Stack **a)
{
	Stack	*tmp;
	Stack	*curr;

	if (!a)
		return ;
	curr = *a;
	while (curr)
	{
		tmp = curr->next;
		curr->value = 0;
		free(curr);
		curr = tmp;
	}
	*a = NULL;
}