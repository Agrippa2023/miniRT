/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_expand.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 04:08:08 by aouichou          #+#    #+#             */
/*   Updated: 2022/12/29 19:49:11 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_array_expand(char **array, char *str)
{
	char	**out;
	int		len;
	int		i;

	i = -1;
	out = NULL;
	if (!str)
		return (array);
	len = ft_array_size(array);
	out = (char **)malloc(sizeof(char *) * (len + 2));
	if (!out)
		return (array);
	out[len + 1] = NULL;
	while (++i < len)
	{
		out[i] = ft_strdup(array[i]);
		if (!out[i])
		{
			ft_array_free(&array);
			ft_array_free(&out);
		}
	}
	out[i] = ft_strdup(str);
	ft_array_free(&array);
	return (out);
}
