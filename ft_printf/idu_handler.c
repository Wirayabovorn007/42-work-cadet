/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiraya <wiraya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:45 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/10/07 17:54:28 by wiraya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n)
{
	char		res;
	long int	num;

	num = n;
	if (num < 0)
	{
		ft_putchar('-');
		num = -num;
	}
	if (num > 9)
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
	else
	{
		res = num + '0';
		ft_putchar(res);
	}
}

int	get_nbr_len(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		i++;
		n = -n;
	}
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	get_unsigned_len(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	ft_put_unsigned_nbr(unsigned int n)
{
	char			res;
	unsigned long	num;

	num = n;
	if (num > 9)
	{
		ft_put_unsigned_nbr((num / 10));
		ft_put_unsigned_nbr((num % 10));
	}
	else
	{
		res = num + '0';
		ft_putchar(res);
	}
}

int	handle_int(va_list args)
{
	int	n;

	n = va_arg(args, int);
	ft_putnbr(n);
	return (get_nbr_len(n));
}

int	handle_unsigned_int(va_list args)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	ft_put_unsigned_nbr(n);
	return (get_unsigned_len(n));
}
