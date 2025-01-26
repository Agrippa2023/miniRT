/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arradd_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:12:17 by aouichou          #+#    #+#             */
/*   Updated: 2023/08/17 09:12:26 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Adds an integer, n, to array by reallocating its content to a new
 * memmory address with size bytes plus an additional byte.
 * 
 * @param array The array in which n will be added.
 * @param n The integer value to be added to the array.
 * @param size The number of bytes currently allocated for the array.
 * @return Returns 0 on success or a positive integer if the operation fails
 * to add n to the array.
 **/
int	ft_arradd_int(int **array, int n, size_t size)
{
	*array = ft_realloc(*array, sizeof(n) * size, (size + 1) * sizeof(n));
	if (*array == NULL)
		return (1);
	(*array)[size] = n;
	return (0);
}
