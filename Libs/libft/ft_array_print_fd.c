/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_print_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:20:18 by aouichou          #+#    #+#             */
/*   Updated: 2023/01/03 18:49:39 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_array_print_fd(char **array, int mod, int fd)
{
	int	i;

	i = 0;
	if (array && array[i])
	{
		while (array[i])
		{
			if (mod)
				ft_putendl_fd(array[i], fd);
			else
				ft_putstr_fd(array[i], fd);
			i++;
		}
	}
}
