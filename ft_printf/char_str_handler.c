/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_str_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:33 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/10/07 14:39:30 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}


int	handle_string(char *str)
{
	int	i;

	i = -1;
	if (!str)
	{
		handle_string("(null)");
		return (6);
	}
	while (str[++i])
	{
		ft_putchar(str[i]);
	}
	return (i);
}
