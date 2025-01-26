/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 05:00:52 by aouichou          #+#    #+#             */
/*   Updated: 2022/06/03 17:24:16 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_u(unsigned int nb, t_printf **flgs)
{
	int	len;
	int	nb_len;

	len = number_len(nb, 10);
	nb_len = len;
	if ((*flgs)->space)
		len++;
	if ((*flgs)->precision > len)
		len = (*flgs)->precision;
	if ((*flgs)->point && !((*flgs)->precision) && nb == 0)
		len = 0;
	if ((*flgs)->wdth && !(*flgs)->dash && !(*flgs)->zero)
		(*flgs)->rtrn += left_padding((*flgs)->wdth - len, 1);
	if ((*flgs)->space && !(*flgs)->sign && !(*flgs)->precision)
		(*flgs)->rtrn = ft_printchar(' ');
	if ((*flgs)->precision && (*flgs)->precision > nb_len)
		(*flgs)->rtrn += left_padding((*flgs)->precision - nb_len, 2);
	if ((*flgs)->zero)
		(*flgs)->rtrn += left_padding((*flgs)->wdth - len, 2);
	if ((*flgs)->point && !((*flgs)->precision))
		(*flgs)->rtrn += 0;
	else
		ft_printnbr(nb, flgs);
	if ((*flgs)->wdth && (*flgs)->dash)
		(*flgs)->rtrn += right_padding((*flgs)->wdth - len);
}

static void	print_sign_padding(int nb, int len, t_printf **flgs)
{
	int	nb_len;

	nb_len = number_len(nb, 10);
	if ((*flgs)->wdth && !(*flgs)->dash && !(*flgs)->zero)
		(*flgs)->rtrn += left_padding((*flgs)->wdth - len, 1);
	if (nb < 0)
		(*flgs)->rtrn += ft_printchar('-');
	if ((*flgs)->sign && nb >= 0)
	{
		(*flgs)->rtrn += ft_printchar('+');
		nb_len++;
	}
	if ((*flgs)->space && nb >= 0 && !(*flgs)->sign)
		(*flgs)->rtrn += ft_printchar(' ');
	if ((*flgs)->precision && (*flgs)->precision > nb_len)
		(*flgs)->rtrn += left_padding((*flgs)->precision - nb_len, 2);
	if ((*flgs)->zero)
		(*flgs)->rtrn += left_padding((*flgs)->wdth - len, 2);
}

void	ft_print_d_i(long long nb, t_printf **flgs)
{
	int	len;

	len = number_len(nb, 10);
	if (nb < 0 || (((*flgs)->sign || (*flgs)->space) && nb >= 0))
		len++;
	if (nb < 0 && (*flgs)->precision >= len)
		len = (*flgs)->precision + 1;
	if ((*flgs)->precision > len)
		len = (*flgs)->precision;
	if ((*flgs)->point && (*flgs)->precision == 0 && nb == 0)
		len = 0;
	print_sign_padding(nb, len, flgs);
	if ((*flgs)->point && !((*flgs)->precision))
		(*flgs)->rtrn += 0;
	else
		ft_printnbr(nb, flgs);
	if ((*flgs)->wdth && (*flgs)->dash)
		(*flgs)->rtrn += right_padding((*flgs)->wdth - len);
}
