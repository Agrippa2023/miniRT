/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_replace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:05:57 by aouichou          #+#    #+#             */
/*   Updated: 2023/03/21 05:10:03 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_array_replace(char ***big, char **small, int n)
{
	char	**temp;
	int		i[3];

	i[0] = -1;
	i[1] = -1;
	i[2] = -1;
	if (!big || !*big)
		return (small);
	if (n < 0 || n >= ft_array_size(*big))
		return (*big);
	temp = ft_calloc(ft_array_size(*big)
			+ ft_array_size(small), sizeof(char *));
	while (temp && big[0][++i[0]])
	{
		if (i[0] != n)
			temp[++i[2]] = ft_strdup(big[0][i[0]]);
		else
		{
			while (small && small[++i[1]])
				temp[++i[2]] = ft_strdup(small[i[1]]);
		}
	}
	ft_array_free(big);
	*big = temp;
	return (*big);
}
