/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_white_spaces.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:16:43 by aouichou          #+#    #+#             */
/*   Updated: 2022/12/16 18:42:52 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_white_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r' || c == ' ')
		return (1);
	return (0);
}

static int	ft_word_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] && !is_white_space(str[i]))
		i++;
	return (i);
}

static int	ft_count_words(char *str)
{
	int	i;
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && is_white_space(*str))
			str++;
		i = ft_word_len(str);
		if (i)
			count++;
		str += i;
	}
	return (count);
}

static char	*ft_strcpy(char *src, int i)
{
	int		j;
	char	*dest;

	j = 0;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (0);
	while (src[j] && j < i)
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	**ft_str_split_white_spaces(char const *s)
{
	int		i;
	int		z;
	int		size;
	char	**tab;
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)s;
	i = -1;
	size = ft_count_words(str);
	tab = (char **)malloc(sizeof(char *) * (size + 1));
	if (!tab)
		return (NULL);
	while (++i < size)
	{
		while (is_white_space(*str))
			str++;
		z = ft_word_len(str);
		tab[i] = ft_strcpy(str, z);
		str += z;
	}
	tab[size] = 0;
	return (tab);
}
