/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 02:39:08 by aouichou          #+#    #+#             */
/*   Updated: 2023/02/10 18:09:13 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchri(const char *s, int c)
{
	int	z;

	z = 0;
	if (!s)
		return (-1);
	while (s[z])
	{
		if (s[z] == c)
			return (z);
		z++;
	}
	if (c == '\0')
		return (z);
	return (-1);
}
