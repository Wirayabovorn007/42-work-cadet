
static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}


int	ft_atoi(char *str)
{
	int	i;
	int	res;
	int sign;
	int	found_num;
	int	found_sign;

	i = -1;
	res = 0;
	sign = 1;
	found_num = 0;
	found_sign = 0;

	while (str[++i])
	{
		// if ((!ft_isdigit(str[i]) && !found_num) || (!ft_isdigit(str[i]) && found_num) || ((str[i] == '+' || str[i] == '-') && found_sign))
		// 	return (0);
		if ((str[i] == '+' || str[i] == '-'))
		{
			if (str[i] == '-')
				sign = -1;
			found_sign = 1;
		}
		if (ft_isdigit(str[i]))
		{
			found_num = 1;
			res = (res * 10) + (str[i] - '0');
		}
	}
	return (res * sign);
}

#include <stdio.h>
int main(){
	printf("%d\n", ft_atoi("-24 degree"));
}