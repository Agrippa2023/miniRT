/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 21:38:08 by aouichou          #+#    #+#             */
/*   Updated: 2022/05/08 21:07:11 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char			*str;
	unsigned int	z;

	str = (char *)s;
	z = 0;
	while (z < n)
	{
		if (str[z] == (char)c)
			return (str + z);
		z++;
	}
	return (NULL);
}
