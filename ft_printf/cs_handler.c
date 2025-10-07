/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_str_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiraya <wiraya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:33 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/10/07 17:40:07 by wiraya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}


int	ft_putstr(char *str)
{
	int	i;

	i = -1;
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[++i])
	{
		ft_putchar(str[i]);
	}
	return (i);
}
