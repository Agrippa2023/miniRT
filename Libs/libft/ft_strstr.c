/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:15:42 by aouichou          #+#    #+#             */
/*   Updated: 2022/12/19 16:16:17 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *string, const char *to_find)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	str = (char *)string;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j] && to_find[j])
		{
			if (!to_find[j + 1])
				return (str + i);
			j++;
		}
		i++;
	}
	return (0);
}
