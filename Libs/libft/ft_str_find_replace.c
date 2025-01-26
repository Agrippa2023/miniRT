/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_find_replace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:22:41 by aouichou          #+#    #+#             */
/*   Updated: 2022/12/19 16:26:23 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_joinstr(char **array, char *str_replace)
{
	int		i;
	char	*temp;
	char	*new_str;

	i = 0;
	temp = ft_strjoin(array[0], str_replace);
	new_str = ft_strjoin(temp, array[1]);
	while (array[i])
		free(array[i++]);
	free(array);
	free(temp);
	return (new_str);
}

static char	**ft_splitstr(char *str, int start, int end)
{
	char	**array;
	int		i;

	i = 0;
	array = (char **)malloc(sizeof(char *) * 3);
	array[0] = (char *)malloc(sizeof(char) * 100000);
	array[1] = (char *)malloc(sizeof(char) * 100000);
	if (!(array) || !(array[1]) || !(array[0]))
		return (NULL);
	array[2] = 0;
	while (i < start)
	{
		array[0][i] = str[i];
		i++;
	}
	array[0][i] = '\0';
	i = 0;
	while (str[end])
	{
		array[1][i] = str[end];
		end++;
		i++;
	}
	array[1][i] = '\0';
	return (array);
}

char	*ft_str_find_replace(char *str, char *str_find, char *str_replace)
{
	char	**array;
	int		start;
	int		end;
	int		i;
	int		j;

	start = 0;
	end = 0;
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == str_find[j] && str_find[j])
		{
			if (!str_find[j + 1])
			{
				start = i;
				end = j + i + 1;
			}
			j++;
		}
		i++;
	}
	array = ft_splitstr(str, start, end);
	return (ft_joinstr(array, str_replace));
}
