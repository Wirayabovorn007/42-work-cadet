/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiraya <wiraya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 14:39:09 by wiraya            #+#    #+#             */
/*   Updated: 2025/09/04 20:05:26 by wiraya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, char searchC)
{
	while (*str)
	{
		if (*str == searchC)
			return ((char *)str);
		str++;
	}
	if (searchC == '\0')
		return ((char *)str);
	return (NULL);
}
