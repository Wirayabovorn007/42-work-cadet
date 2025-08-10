/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiraya <wiraya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 16:28:12 by wiraya            #+#    #+#             */
/*   Updated: 2025/08/10 16:40:41 by wiraya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	set_and_check_val(long *num, int n, long *tmp, int *len)
{
	*num = n;
	*len = 0;
	*tmp = *num;
	if (n <= 0)
		*len = 1;
	if (*num < 0)
		*tmp = -(*num);
}

static void	op_tmp(long *tmp, int *len)
{
	while (*tmp > 0)
	{
		*tmp /= 10;
		(*len)++;
	}
}

char	*ft_itoa(int n)
{
	long	num;
	long	tmp;
	int		len;
	char	*str;

	set_and_check_val(&num, n, &tmp, &len);
	op_tmp(&tmp, &len);
	str = (char *)malloc(len + 1);
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
// 	printf("%s\n", ft_itoa(1023010103));
// 	printf("%s\n", ft_itoa(-123));
// 	printf("%s\n", ft_itoa(0));
// }