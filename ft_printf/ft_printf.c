#include "ft_printf.h"


void	separate_case(const char *format, va_list args)
{
	if (*format == 'c')
		handle_char(args);
	if (*format == 's')
		handle_string(args);
	// if (*format == 'p')
	//
	if (*format == 'd')
		handle_int(args);
	//if (*format == 'i')
	if (*format == 'u')
		handle_unsinged_int(args);
	//if (*format == 'x' || *format == 'X')
	if (*format == '%')
		write(1, "%", 1);
}

int ft_printf(const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			separate_case(format, args);
		}
		else
			write(1, &(*format), 1);
		format++;
	}
	va_end(args);
	return 0;
}

int main()
{
	ft_printf("Char: %c and %c\nString: %s\nInteger: %d %d\nUnsinged int: %u %u\nPercent: %%", 'A', 'B', "Wirayabovorn Boonpriam", 1, -1, -22, 81);
}