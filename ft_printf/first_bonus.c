#include "ft_printf.h"

void	print_zeropad(int n)
{
	int	i;

	i = -1;
	while (++i < n)
		ft_putchar('0');
}

int	is_not_specifier(char c)
{
	return (!(c == 'd' || c == 'i' || c == 'u' 
		|| c == 'x' || c == 'X' || c == 'p'));
}

int	zeropad_validator(const char **f, va_list args)
{
	int		num;
	int		len;
	int		padwidth;

	(*f)++;
	len = 0;
	padwidth = 0;
	while (is_not_specifier(**f))
	{
		if (**f == '%')
			return (0);
		if (**f >= '0' && **f <= '9')
			padwidth = (padwidth * 10) + (**f - '0');
		(*f)++;
	}
	num = va_arg(args, int);
	len = get_nbr_len(num);
	if (padwidth <= len)
	{
		ft_putnbr(num);
		return (len);
	}
	if (num < 0)
	{
		ft_putchar('-');
		num  = -num;
	}
	print_zeropad(padwidth - len);
	ft_putnbr(num);
	return (padwidth);
}
