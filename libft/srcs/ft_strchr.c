/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiraya <wiraya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 14:39:09 by wiraya            #+#    #+#             */
/*   Updated: 2025/08/10 14:39:54 by wiraya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(char *str, char searchC)
{
	while (*str)
	{
		if (*str == searchC)
			return (str);
		str++;
	}
	if (searchC == '\0')
		return (str);
	return (NULL);
}
