#include "ft_printf.h"

void	print_zeropad(int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar('0');
		i++;
	}
}

int	is_not_specifier(char c)
{
	return (!(c == 'd' || c == 'i' || c == 'u' 
		|| c == 'x' || c == 'X' || c == 'p'));
}

int	zeropad_validator(const char *f, va_list args, int i)
{
	int		len;
	int		padwidth;

	i++;
	len = 0;
	padwidth = 0;
	while (is_not_specifier(f[i]))
	{
		if (f[i] == '%')
			return (0);
		if (f[i] >= '0' && f[i] <= '9')
			padwidth = (padwidth * 10) + (f[i] - '0');
		i++;
	}
	len = get_nbr_len(va_arg(args, int));
	if (padwidth < len)
		return (handle_int(args));
	print_zeropad(padwidth);
	handle_int(args);
	return (padwidth);
}
