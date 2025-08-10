/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiraya <wiraya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 14:40:11 by wiraya            #+#    #+#             */
/*   Updated: 2025/08/10 14:40:59 by wiraya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(char *str, char searchC)
{
	char	*last;

	last = NULL;
	while (*str)
	{
		if (*str == searchC)
			last = str;
		str++;
	}
	if (searchC == '\0')
		return (NULL);
	return (last);
}
