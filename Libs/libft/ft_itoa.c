/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 00:28:29 by aouichou          #+#    #+#             */
/*   Updated: 2022/05/06 03:30:00 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	str_len(long n)
{
	int	z;

	z = 0;
	while (n > 0)
	{
		z++;
		n = n / 10;
	}
	return (z);
}

static char	*ft_fill_str(long nb, char *str, int neg, int z)
{
	while (nb > 0)
	{
		str[--z] = (nb % 10) + 48;
		nb = nb / 10;
	}
	if (neg == 1)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		neg;
	int		z;
	long	nb;

	if (n == 0)
		return (ft_strdup("0"));
	neg = 0;
	nb = (long)n;
	if (nb < 0)
	{
		neg = 1;
		nb *= -1;
	}
	z = str_len(nb) + neg;
	str = (char *)malloc((z + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[z] = '\0';
	return (ft_fill_str(nb, str, neg, z));
}
