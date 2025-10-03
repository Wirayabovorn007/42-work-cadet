#include "ft_printf.h"


void	check_specifier(const char *format, va_list args)
{
	if (*format == 'c')
		handle_char(args);
	if (*format == 's')
		handle_string(args);
	if (*format == 'p')
		handle_p(args);
	if (*format == 'd' || *format == 'i')
		handle_int(args);
	if (*format == 'u')
		handle_unsinged_int(args);
	if (*format == 'x' || *format == 'X')
		handle_x(args, *format);
	if (*format == '%')
		write(1, "%", 1);
}

int ft_printf(const char *format, ...)
{
	int		len;
	va_list	args;

	if (!format)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			len++;
			check_specifier(format, args);
		}
		else
			write(1, &(*format), 1);
		format++;
		len++;
	}
	va_end(args);
	return (len);
}

// int main()
// {
// 	int a = 102310221;
// 	ft_printf("Char: %c and %c\nString: %s\nInteger: %d %d\nUnsinged int: %u %u\nPercent: 20%%\nOctal 012: %i and Hex 0xA: %i\nMemmory %p\nx 48879: %x %X", 'A', 'B', "Wirayabovorn Boonpriam", 1, -1, -22, 81, 012, 0xA, &a, 3735928559, 3735928559);
// }