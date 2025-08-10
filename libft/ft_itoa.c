#include <stdlib.h>

char	*ft_itoa(int n)
{
	long	num;
	long	tmp;
	int		len;
	char	*str;

	num = n;
	tmp = num;
	if (n <= 0)
		len = 1;
	if (num < 0)
		tmp = -num;
	while (tmp > 0)
	{
		tmp /= 10;
		len++;
	}
	str = malloc(sizeof(char) + len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		str[--len] = '0' + (num % 10);
		num /= 10;
	}
	return (str);
}

// #include <stdio.h>
// int main(){
// 	printf("%s\n", ft_itoa(123));
// 	printf("%s\n", ft_itoa(1023));
// 	printf("%s\n", ft_itoa(-123));
// }