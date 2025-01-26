/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:03:52 by aouichou          #+#    #+#             */
/*   Updated: 2022/07/05 16:30:39 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlength(unsigned long long value, int base_l)
{
	int	z;

	z = 0;
	if (value == 0)
		return (1);
	while (value != 0)
	{
		z += 1;
		value /= base_l;
	}
	return (z);
}

void	array_fill(char *nbr, unsigned long long value, char *base, int len)
{
	int	base_l;

	base_l = ft_strlen(base);
	while (value != 0 && len >= 0)
	{
		nbr[len] = base[value % base_l];
		value /= base_l;
		len--;
	}
}

char	*ft_itoa_base(unsigned long long value, char *base)
{
	int					l;
	char				*nbr;
	int					base_l;

	l = 0;
	base_l = ft_strlen(base);
	if (base_l < 2)
		return (NULL);
	l = ft_intlength(value, base_l);
	nbr = (char *)malloc(sizeof(char) * (l + 1));
	if (!nbr)
		return (NULL);
	if (value == 0)
		nbr[0] = '0';
	else
		array_fill(nbr, value, base, l - 1);
	nbr[l] = '\0';
	return (nbr);
}
