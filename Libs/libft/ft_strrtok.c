/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrtok.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:05:59 by aouichou          #+#    #+#             */
/*   Updated: 2022/12/14 16:08:19 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrtok(const char *s, int c)
{
	int		z;
	int		y;
	int		i;
	char	*dst;

	z = -1;
	y = -1;
	i = 0;
	while (s[++z])
	{
		if (s[z] == c)
		{
			y = z;
			break ;
		}
	}
	while (s[z])
		z++;
	dst = (char *)malloc(sizeof(char) * (z - y));
	if ((c == '\0' && y == -1) || !(dst))
		return (NULL);
	while (++y < z)
		dst[i++] = s[y];
	dst[i] = '\0';
	return (dst);
}
