#include "../push_swap.h"

void	swap(Stack **head)
{
	if (!*head || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(Stack **a)
{
	swap(a);
	write(1, "sa\n", 4);
}

void	sb(Stack **b)
{
	swap(b);
	write(1, "sb\n", 4);
}

void	ss(Stack **a, Stack **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 4);
}