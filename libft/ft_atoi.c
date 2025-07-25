
static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

// #include <stdio.h>
// int main(){
// 	printf("%d\n", ft_atoi("-24 degree"));
// 	printf("%d\n", ft_atoi("--24 degree"));
// 	printf("%d\n", ft_atoi(" +2a4 degree"));
// 	printf("%d\n", ft_atoi("a24 degree"));
// }