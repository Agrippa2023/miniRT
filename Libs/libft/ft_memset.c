/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 21:02:36 by aouichou          #+#    #+#             */
/*   Updated: 2022/05/05 23:52:02 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned int	z;
	unsigned char	*s;

	z = 0;
	s = (unsigned char *)str;
	while (z < n)
		s[z++] = (unsigned char)c;
	return (str);
}
