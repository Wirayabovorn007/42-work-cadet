/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:42 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/10/07 14:04:52 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex(unsigned long int n)
{
	char	c;

	if (n >= 16)
		print_hex(n / 16);
	if (n % 16 < 10)
		c = (n % 16) + '0';
	else
		c = (n % 16 - 10) + 'a';
	write(1, &c, 1);
}

void	print_hex_x(unsigned long int n, const char x)
{
	int		is_upper;
	char	c;

	is_upper = x == 'X';
	if (n >= 16)
		print_hex_x(n / 16, x);
	if (n % 16 < 10)
		c = (n % 16) + '0';
	else
	{
		c = (n % 16 - 10);
		if (is_upper)
			c += 'A';
		else
			c += 'a';
	}
	write(1, &c, 1);
}

// int	get_hex_len()
// {
	
// }

int	handle_p(va_list args)
{
	void			*ptr;
	unsigned long	addr;

	ptr = va_arg(args, void *);
	addr = (unsigned long)ptr;
	if (!ptr)
		write(1, "0x0", 3);
	else
	{
		write(1, "0x", 2);
		print_hex(addr);
	}
	return 1;
}

int	handle_x(va_list args, const char x)
{
	void	*ptr;

	ptr = va_arg(args, void *);
	if (ptr)
		print_hex_x((unsigned long int)ptr, x);
	return 1;
}
