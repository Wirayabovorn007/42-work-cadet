/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiraya <wiraya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:36 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/10/07 21:50:26 by wiraya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int check_bonus_specifier(const char *format, va_list args)
{
	//if (*format == '-')

	if (*format == '0')
		return (zeropad_validator(format, args));
	//if (*format == '.')
	return (0);
}

int	check_specifier(const char *format, va_list args)
{
	if (*format == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (*format == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (*format == 'p')
		return (handle_p(args));
	if (*format == 'd' || *format == 'i')
		return (handle_int(args));
	if (*format == 'u')
		return (handle_unsigned_int(args));
	if (*format == 'x' || *format == 'X')
		return (handle_x(args, *format));
	if (*format == '%')
		return (ft_putchar('%'));
	return (check_bonus_specifier(format, args));
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	args;

	if (!format)
		return (-1);
	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			len += check_specifier(format, args);
		}
		else
		{
			write(1, &(*format), 1);
			len++;
		}
		format++;
	}
	va_end(args);
	return (len);
}
