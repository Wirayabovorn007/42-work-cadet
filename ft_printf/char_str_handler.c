/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_str_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:33 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/10/07 14:12:29 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_strlen(char *c)
{
	int	i;

	i = -1;
	while (c[++i])
		;
	return (i);
}

int	handle_string(va_list args)
{
	char	*str;

	str = (char *)va_arg(args, char *);
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
	return (ft_strlen(str));
}
