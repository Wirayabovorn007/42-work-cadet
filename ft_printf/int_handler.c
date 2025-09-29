#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	res;
	long	num;

	num = n;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num = -num;
	}
	if (num > 9)
	{
		ft_putnbr_fd((int)(num / 10), fd);
		ft_putnbr_fd((int)(num % 10), fd);
	}
	else
	{
		res = num + '0';
		ft_putchar_fd(res, fd);
	}
}

void	ft_put_unsigned_nbr_fd(unsigned int n, int fd)
{
	char	res;
	unsigned long	num;

	num = n;
	if (num > 9)
	{
		ft_putnbr_fd((num / 10), fd);
		ft_putnbr_fd((num % 10), fd);
	}
	else
	{
		res = num + '0';
		ft_putchar_fd(res, fd);
	}
}

void	handle_int(va_list args)
{
	int	n;

	n = va_arg(args, int);
	ft_putnbr_fd(n, 1);
}

void	handle_unsinged_int(va_list args)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	ft_put_unsigned_nbr_fd(n, 1);
}