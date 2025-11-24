

#include <unistd.h>

int ft_strcmp(char *s1, char s2)
{
	while (*s1 && (*s1 == s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - s2);
}

void print_naja(char *str)
{
	int i =0;

	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int main(int argc, char *argv[])
{
	if (argc != 4 || !argv[1])
	{
		write(1, "\n", 1);
		return 1;
	}
	char *str = argv[1];
	char* search = argv[2];
	char* replace = argv[3];

	int i =0;
	while (str[i])
	{
		if (ft_strcmp(search, str[i]) == 0)
			print_naja(replace);
		else
			write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return 0;
}