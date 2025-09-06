/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 11:18:43 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/09/06 11:22:28 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_lstdelone(t_list *lst, void (*del)(void *))
{
    if (!(lst && del))
        return ;
    del(lst->content);
    free(lst);
}
