/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 22:54:38 by aouichou          #+#    #+#             */
/*   Updated: 2022/05/08 20:54:36 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	z;
	size_t	y;

	if (!s1)
		return (NULL);
	y = 0;
	while (s1[y] && ft_strchr(set, s1[y]))
		y++;
	z = ft_strlen(s1) - 1;
	i = 0;
	while (s1[z - i] && ft_strrchr(set, s1[z - i]))
		i++;
	return (ft_substr(s1, y, z - y - i + 1));
}
