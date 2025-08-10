#include <unistd.h>

void	ft_putnbr(int n)
{
	char	res;
	long	num;

	num = n;
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	if (num > 9)
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}else{
		res = num + '0';
		write(1, &res, 1);
	}	
}
