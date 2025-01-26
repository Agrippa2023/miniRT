/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 21:46:56 by aouichou          #+#    #+#             */
/*   Updated: 2022/05/03 21:49:33 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	unsigned char	c1;
	unsigned char	c2;
	unsigned int	z;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	c1 = 0;
	c2 = 0;
	z = 0;
	while (z < n)
	{
		c1 = (unsigned char)str1[z];
		c2 = (unsigned char)str2[z];
		if (c1 != c2)
			return (c1 - c2);
		z++;
	}
	return (0);
}
