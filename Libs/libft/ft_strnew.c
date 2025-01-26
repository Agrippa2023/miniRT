/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 03:54:00 by aouichou          #+#    #+#             */
/*   Updated: 2022/05/28 03:54:19 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	z;

	z = 0;
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!(str))
		return (NULL);
	while (z < size)
		str[z++] = '\0';
	str[z] = '\0';
	return (str);
}
