/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:15:54 by aouichou          #+#    #+#             */
/*   Updated: 2023/08/17 09:16:03 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copies the src string to dest and returns a 
 * pointer to the end of dest.
 * @param dest The string to receive the copy.
 * @param src The string to be copied.
 * @return Return a pointer to the end of the string dest
*/
char	*ft_strcpy_end(char *dest, char *src)
{
	while (*src != '\0')
		*dest++ = *src++;
	*dest = '\0';
	return (dest);
}
