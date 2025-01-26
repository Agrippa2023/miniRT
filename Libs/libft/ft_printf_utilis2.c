/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilis2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 20:12:08 by aouichou          #+#    #+#             */
/*   Updated: 2022/06/03 17:24:25 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	number_len(long long nb, int base)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		len++;
		nb /= base;
	}
	return (len);
}

int	number_p_len(unsigned long long nb, int base)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		len++;
		nb /= base;
	}
	return (len);
}

int	left_padding(int n, int mod)
{
	char	c1;
	char	c2;
	int		i;

	i = 0;
	c1 = ' ';
	c2 = '0';
	while (i < n)
	{
		if (mod == 1)
			write(1, &c1, 1);
		if (mod == 2)
			write(1, &c2, 1);
		i++;
	}
	return (i);
}

int	right_padding(int n)
{
	char	c;
	int		i;

	i = 0;
	c = ' ';
	while (i < n)
	{
		write(1, &c, 1);
		i++;
	}
	return (i);
}

int	is_specifier(char c)
{
	char	*specifiers;
	int		i;

	specifiers = "cspdiuxX%";
	i = 0;
	while (specifiers[i])
	{
		if (specifiers[i] == c)
			return (1);
		i++;
	}
	return (0);
}
