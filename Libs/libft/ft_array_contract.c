/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_contract.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:38:29 by aouichou          #+#    #+#             */
/*   Updated: 2023/03/21 07:07:43 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_array_contract(char ***array, int z)
{
	char	**new_array;
	char	**tmp;
	int		i[2];

	tmp = *array;
	new_array = (char **)malloc(sizeof(char *) * ft_array_size(tmp));
	if (!array || !*array || !new_array)
		return (NULL);
	i[0] = 0;
	i[1] = 0;
	while (tmp[i[0]])
	{
		if (i[0] == z)
		{
			if (tmp[i[0] + 1])
				i[0]++;
			else
				break ;
		}
		new_array[i[1]++] = ft_strdup(tmp[i[0]++]);
	}
	ft_array_free(array);
	new_array[i[1]] = NULL;
	*array = new_array;
	return (*array);
}
