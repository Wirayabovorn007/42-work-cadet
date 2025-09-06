/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 10:36:41 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/09/06 10:46:33 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_lstsize(t_list *lst)
{
    int     c;
    t_list  *current;

    if (!lst)
        return (0);
    current = lst;
    c = 1;
    while (current != NULL)
    {
        if (current -> next == NULL)
            return (c);
        c++;
        current = current->next;
    }
    return (c);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int a = 1;
// 	int b = 10;
// 	int c = 100;

// 	t_list *first = ft_lstnew(&a);
// 	t_list *second = ft_lstnew(&b);
// 	t_list *third = ft_lstnew(&c);

// 	ft_lstadd_front(&third, second);
// 	ft_lstadd_front(&second, first);
// 	 t_list  *current;
//         int     i;

//         current = first;
//         i = 0;
//         while (current != NULL)
//         {
//                 printf("Node %d: %d\n", i, *(int *)current->content);
//                 current = current->next;
//                 i++;
//         }
// 	int k = 0;
// 	k = ft_lstsize(first);
// 	printf("%d", k);
// 	return (0);
// }