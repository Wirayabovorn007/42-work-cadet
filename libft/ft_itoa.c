/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:12:58 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/09/05 21:59:59 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	get_nbr_len(long num)
{
	long	l;

	l = 0;
	if (num <= 0)
		l += 1;
	while (num)
	{
		l++;
		num /= 10;
	}
	return (l);
}

char	*ft_itoa(int n)
{
	long	len;
	char	*res;
	long	temp;

	temp = n;
	len = get_nbr_len(temp);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (temp == 0)
		res[0] = '0';
	if (temp < 0)
	{
		res[0] = '-';
		temp = -temp;
	}
	while (temp)
	{
		res[--len] = (temp % 10) + '0';
		temp /= 10;
	}
	return (res);
}

// #include <stdio.h>
// int main(){
// 	printf("%s\n", ft_itoa(123));
// 	printf("%s\n", ft_itoa(1023010103));
// 	printf("%s\n", ft_itoa(-123));
// 	printf("%s\n", ft_itoa(0));
// }