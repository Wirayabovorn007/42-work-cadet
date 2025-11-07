/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 20:55:51 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/11/07 21:46:40 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap()
{

}


#include <stdio.h>
int	main(int argc, char *argv[])
{
	Stack *st;
	int	i;
	int	max;

	max = argc - 1;
	i = argc + 1;
	st = initialize(st, max);
	if (!st)
	{
		printf("Initialize failed\n");
		return (1);
	}
	printf("Initialzie success!\n");
	while (--i > 1)
		push(ft_atoi(argv[i]), st, max);
	int j = 0;
	int *arr;
	arr = st->arr;
	while (j < argc - 1)
	{
		printf("%d\n", arr[j]);
		j++;
	}
}

// ./push_swap 2 1 3 6 5 8
// 2
// 1
// 3
// 6
// 5
// 8

// sa 
// 1
// 2
// 3
// 6
// 5
// 8

// pb * 3
// 8 3
// 5 2
// 6 1

// sa
// 5 3
// 8 2
// 6 1

// pa*3
// 1
// 2
// 3
// 5
// 8
// 6
