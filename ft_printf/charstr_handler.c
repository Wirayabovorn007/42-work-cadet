#include "ft_printf.h"

int	ft_strlen(char *c)
{
	int	i;

	i = -1;
	while (c[++i])
		;
	return (i);
}

void	handle_char(va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
	write(1, &c, 1);
}

void	handle_string(va_list args)
{
	char	*str;

	str = (char *)va_arg(args, char *);
	while (*str)
	{
		write(1, &(*str), 1);
		str++;
	}
}