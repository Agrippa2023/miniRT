/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 00:36:01 by aouichou          #+#    #+#             */
/*   Updated: 2022/05/04 01:55:32 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_len(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] != c))
		i++;
	return (i);
}

static int	ft_count_words(char *str, char c)
{
	int	i;
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && (*str == c))
			str++;
		i = ft_word_len(str, c);
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

char	**ft_split(char const *s, char c)
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
	size = ft_count_words(str, c);
	tab = (char **)malloc(sizeof(char *) * (size + 1));
	if (!tab)
		return (NULL);
	while (++i < size)
	{
		while (*str == c)
			str++;
		z = ft_word_len(str, c);
		tab[i] = ft_strcpy(str, z);
		str += z;
	}
	tab[size] = 0;
	return (tab);
}
