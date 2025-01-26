/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 00:50:31 by aouichou          #+#    #+#             */
/*   Updated: 2022/06/03 17:24:20 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printchar(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
	return (i);
}

void	ft_printnbr(long long n, t_printf **flgs)
{
	long long	nb;

	nb = (long long)n;
	if (n < 0)
		nb *= -1;
	if (nb < 10)
		(*flgs)->rtrn += ft_printchar(((char)nb + 48));
	else if (nb >= 10)
	{
		ft_printnbr((nb / 10), flgs);
		ft_printnbr((nb % 10), flgs);
	}
}

void	flgs_init(t_printf *flgs)
{
	flgs->wdth = 0;
	flgs->precision = 0;
	flgs->zero = 0;
	flgs->point = 0;
	flgs->dash = 0;
	flgs->rtrn = 0;
	flgs->sign = 0;
	flgs->percent = 0;
	flgs->space = 0;
	flgs->hash = 0;
}
