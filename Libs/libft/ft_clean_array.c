/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:01:41 by aouichou          #+#    #+#             */
/*   Updated: 2023/08/17 09:01:59 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Cleans a two-dimensional array and its content. The array must be NULL
 * terminated.
 * @param array The address of a two-dimensional array.
 * @param del The address of the function used to delete the content of the
 * array;
 */
void	ft_clean_array(void **array, void (*del)(void *))
{
	int	i;

	if (array == NULL)
		return ;
	i = 0;
	while (array[i])
	{
		del(array[i]);
		i++;
	}
	free(array);
}
