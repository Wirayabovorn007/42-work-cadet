/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:15:01 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/09/05 23:29:47 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(const char *str, int n)
{
	char		search;
	const char	*last;

	last = NULL;
	search = (char)n;
	while (*str != '\0')
	{
		if (*str == search)
			last = str;
		str++;
	}
	if (search == '\0')
		return ((char *)str);
	return ((char *)last);
}
