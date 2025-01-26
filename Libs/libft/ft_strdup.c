/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 21:23:59 by aouichou          #+#    #+#             */
/*   Updated: 2022/05/06 01:12:58 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	unsigned int	size;
	char			*str;

	size = ft_strlen(src) + 1;
	str = (char *)malloc(sizeof(char) * size);
	if (!str)
		return (NULL);
	size = ft_strlcpy(str, src, size);
	return (str);
}
