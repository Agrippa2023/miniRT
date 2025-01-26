/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 21:33:03 by aouichou          #+#    #+#             */
/*   Updated: 2022/05/08 00:07:54 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		z;
	char	*str;
	int		y;

	str = (char *)s;
	z = 0;
	y = -1;
	while (str[z])
	{
		if (str[z] == (char)c)
			y = z;
		z++;
	}
	if ((y != -1) & (c != '\0'))
		return (str + y);
	if (c == '\0')
		return (str + z);
	return (0);
}
