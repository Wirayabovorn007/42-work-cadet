/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:10:56 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/11/24 14:10:57 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
