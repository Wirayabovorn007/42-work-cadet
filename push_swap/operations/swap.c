#include "../include/push_swap.h"

void	swap(Stack **head)
{
	Stack *first;
	Stack *second;
	if (!*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;	
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*head = second;
}

void	sa(Stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(Stack **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(Stack **a, Stack **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}