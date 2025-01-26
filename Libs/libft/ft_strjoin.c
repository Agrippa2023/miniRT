/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 22:49:43 by aouichou          #+#    #+#             */
/*   Updated: 2022/05/03 22:53:08 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	z;
	size_t	y;
	int		w;

	if (s1 && s2)
	{
		z = ft_strlen(s1) + ft_strlen(s2);
		y = 0;
		w = 0;
		str = (char *)malloc((z + 1) * sizeof(char));
		if (!str)
			return (NULL);
		while (s1[w])
			str[y++] = s1[w++];
		w = 0;
		while (s2[w])
			str[y++] = s2[w++];
		str[y] = '\0';
		return (str);
	}
	return (NULL);
}
