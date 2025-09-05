/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:14:08 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/09/05 14:41:04 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int searchC)
{
	while (*str != '\0')
	{
		if (*str == (char )searchC)
			return ((char *)str);
		str++;
	}
	if ((char )searchC == '\0')
		return ((char *)str);
	return (NULL);
}
