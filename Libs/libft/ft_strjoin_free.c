/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 03:13:37 by aouichou          #+#    #+#             */
/*   Updated: 2022/12/27 06:39:37 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2, int mod)
{
	char	*str;
	size_t	z;
	size_t	y;
	int		w;

	z = ft_strlen(s1) + ft_strlen(s2);
	y = 0;
	w = 0;
	str = (char *)malloc((z + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1 && s1[w])
		str[y++] = s1[w++];
	w = 0;
	while (s2 && s2[w])
		str[y++] = s2[w++];
	str[y] = '\0';
	if (mod == 1)
		free(s1);
	if (mod == 2)
	{
		free(s1);
		free(s2);
	}
	return (str);
}
