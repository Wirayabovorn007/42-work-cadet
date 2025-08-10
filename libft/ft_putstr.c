#include <unistd.h>

void	ft_putstr(char const *s)
{
	int	i;

	i = -1;
	while (s[++i])
		write(1, &s[i], 1);
}
