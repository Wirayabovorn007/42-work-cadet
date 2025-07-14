

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

// #include <stdio.h>
// int main()
// {
// 	printf("%c\n",ft_toupper('a'));
// 	printf("%c\n",ft_toupper('-'));
// 	return 0;
// }