#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

typedef struct stack
{
	int			index;
	int			value;
	int			push_cost;
	int			is_cheapest;
	int			is_above_median;
	struct stack *target;
	struct stack *next;
	struct stack *prev;
}	Stack;

int		push_swap(int argc, char *argv[]);
int		can_split(char *str);
char	**split_num(char *s, char c);
int		init_stack(Stack **a, char *argv[]);
int		has_err(char *argv[]);
long	ft_atol(char *str);
void	free_split_array(char **array);
int		print_err();
int		ft_isdigit(int c);
int		can_join_split(char *argv[]);
char	**join_n_split(char *argv[]);
int		sorted(Stack *a);
void	sort_stack(Stack** a, Stack **b);
int		len_stack(Stack *a);
Stack*	get_last_node(Stack *node);
void	update_index(Stack *stack);
Stack	*get_min(Stack *stack);
Stack	*get_max(Stack *stack);
void	update_a(Stack *a, Stack *b);
void	move_cheapest_a_to_b(Stack **a, Stack **b);
void	update_b(Stack *a, Stack *b);
void	move_cheapest_b_to_a(Stack **a, Stack **b);
void	free_stack(Stack **a);

void	pa(Stack **a, Stack **b);
void	pb(Stack **a, Stack **b);
void	rra(Stack **a);
void	rrb(Stack **b);
void	rrr(Stack **a, Stack **b);
void	ra(Stack **a);
void	rb(Stack **b);
void	rr(Stack **a, Stack **b);
void	sa(Stack **a);
void	sb(Stack **b);
void	ss(Stack **a, Stack **b);

#endif