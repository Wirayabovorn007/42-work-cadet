/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiraya <wiraya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 15:31:13 by wiraya            #+#    #+#             */
/*   Updated: 2025/08/10 16:27:57 by wiraya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count_words(char const *s, char delimiter)
{
	int	i;
	int	new_word;

	new_word = 0;
	i = 0;
	while (*s)
	{
		if (*s == delimiter)
			new_word = 0;
		else
		{
			if (!new_word)
			{
				new_word = 1;
				i++;
			}
		}
		s++;
	}
	return (i);
}

static char	*word_dup(char const *str, int len)
{
	int		i;
	char	*dup;

	dup = (char *)malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static void	free_arr(char **arr, int i)
{
	while (i > 0)
		free(arr[--i]);
	free(arr);
}

static void	skip_and_count_len(char const **s, int *len, char c, int op)
{
	if (op == 1)
	{
		while (**s == c)
			(*s)++;
	}
	else
	{
		while (**s && **s != c)
		{
			(*s)++;
			(*len)++;
		}
	}
}

char	**ft_strsplit(char const *s, char c)
{
	char		**arr;
	const char	*temp;
	int			i;
	int			words;
	int			len;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	arr = (char **)malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	i = -1;
	while (++i < words)
	{
		len = 0;
		skip_and_count_len(&s, &len, c, 1);
		temp = s;
		skip_and_count_len(&s, &len, c, 2);
		arr[i] = word_dup(temp, len);
		if (!arr[i])
			return (free_arr(arr, i), NULL);
	}
	arr[i] = NULL;
	return (arr);
}

// #include <stdio.h>
// int main(){
// 	char **arr = ft_strsplit("***d*3232*oioo_* 21 p*0*n*", '*');
// 	int i = -1;
// 	while (arr[++i]) printf("%s\n", arr[i]);
// }