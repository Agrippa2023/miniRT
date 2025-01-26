/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_dup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 20:08:11 by aouichou          #+#    #+#             */
/*   Updated: 2022/12/28 18:44:27 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_array_dup(char **array)
{
	int		i;
	char	**dup_array;

	i = 0;
	dup_array = NULL;
	if (array)
	{
		i = ft_array_size(array) + 1;
		dup_array = (char **)malloc(i * sizeof(char *));
		if (!dup_array)
			return (NULL);
		i = -1;
		while (array[++i])
			dup_array[i] = ft_strdup(array[i]);
		dup_array[i] = NULL;
	}
	return (dup_array);
}
