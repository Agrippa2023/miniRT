/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:36:22 by aouichou          #+#    #+#             */
/*   Updated: 2023/02/09 15:41:26 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_swap(char	**str1, char **str2)
{
	char	*temp;

	temp = ft_strdup(*str1);
	free(*str1);
	*str1 = ft_strdup(*str2);
	free(*str2);
	*str2 = ft_strdup(temp);
	free(temp);
}

char	**ft_array_sort(char **array)
{
	int		i[2];
	size_t	z;
	char	**sorted_array;

	if (array && *array)
	{
		i[0] = -1;
		sorted_array = ft_array_dup(array);
		while (++i[0] < ft_array_size(array))
		{
			i[1] = -1;
			while (++i[1] < ft_array_size(array) - i[0] - 1)
			{
				z = ft_strlen(sorted_array[i[1]]);
				if (ft_strlen(sorted_array[i[1] + 1]) > z)
					z = ft_strlen(sorted_array[i[1] + 1]);
				if (ft_strncmp(sorted_array[i[1]],
						sorted_array[i[1] + 1], z) > 0)
					ft_swap(&sorted_array[i[1]], &sorted_array[i[1] + 1]);
			}
		}
		return (sorted_array);
	}
	return (NULL);
}
