#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putendl_fd(char const *s, int fd)
{
	if (!*s)
		return ;
	while (*s)
		ft_putchar_fd(*s++, fd);
	write(1, "\n", 1);
}