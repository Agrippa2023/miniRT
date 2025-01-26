/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 21:11:36 by aouichou          #+#    #+#             */
/*   Updated: 2022/06/03 17:24:11 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_p_sign_padding(long long nb, int *len, t_printf **flgs)
{
	int	nb_len;

	nb_len = number_p_len(nb, 16) - 2;
	if ((*flgs)->space)
	{
		(*flgs)->rtrn += ft_printchar(' ');
		(*len)++;
	}
	if ((*flgs)->zero || (*flgs)->precision)
	{
		(*flgs)->rtrn += ft_printstr("0x");
		len += 2;
		nb_len += 2;
	}
	if ((*flgs)->wdth && !((*flgs)->dash) && !((*flgs)->zero))
		(*flgs)->rtrn += left_padding((*flgs)->wdth - *len - 2, 1);
	if ((*flgs)->precision && (*flgs)->precision > nb_len)
		(*flgs)->rtrn += left_padding((*flgs)->precision - nb_len, 2);
	if ((*flgs)->zero)
		(*flgs)->rtrn += left_padding((*flgs)->wdth - *len, 2);
}

void	ft_print_p(void *ptr, t_printf **flgs)
{
	char	*number;
	int		len;

	len = number_p_len((unsigned long long)ptr, 16);
	if ((*flgs)->sign)
	{
		len++;
		(*flgs)->rtrn += ft_printchar('+');
	}
	if ((*flgs)->precision > len)
		len = (*flgs)->precision;
	if (ptr == 0)
		(*flgs)->rtrn += ft_printstr("(nil)");
	else
	{
		print_p_sign_padding((long long)ptr, &len, flgs);
		if (!((*flgs)->zero) && !((*flgs)->precision))
			(*flgs)->rtrn += ft_printstr("0x");
		number = ft_itoa_base((long long)ptr, "0123456789abcdef");
		(*flgs)->rtrn += ft_printstr(number);
		free(number);
	}
	if ((*flgs)->wdth > len && (*flgs)->dash)
		(*flgs)->rtrn += right_padding((*flgs)->wdth - len - 2);
}

static void	print_sign_padding(long long nb, int len, t_printf **flgs,
								char c)
{
	int	nb_len;

	nb_len = number_len(nb, 16);
	if ((*flgs)->hash && nb != 0)
		len += 2;
	if (nb < 0 && ((*flgs)->zero || (*flgs)->point))
		(*flgs)->rtrn += ft_printchar('-');
	if ((*flgs)->wdth && !((*flgs)->dash) && !((*flgs)->zero))
		(*flgs)->rtrn += left_padding((*flgs)->wdth - len, 1);
	if ((*flgs)->hash && nb != 0)
	{
		if (c == 'X')
			(*flgs)->rtrn += ft_printstr("0X");
		else if (c == 'x')
			(*flgs)->rtrn += ft_printstr("0x");
	}
	if ((*flgs)->precision && (*flgs)->precision > nb_len)
		(*flgs)->rtrn += left_padding((*flgs)->precision - nb_len, 2);
	if ((*flgs)->zero)
		(*flgs)->rtrn += left_padding((*flgs)->wdth - len, 2);
}

void	ft_print_x(long long nb, t_printf **flgs, char c)
{
	char	*number;
	int		len;

	len = number_len(nb, 16);
	if ((*flgs)->precision > len)
		len = (*flgs)->precision;
	if ((nb < 0) && ((*flgs)->precision >= len))
		len = (*flgs)->precision + 1;
	if ((*flgs)->point && !((*flgs)->precision) && nb == 0)
		len = 0;
	print_sign_padding(nb, len, flgs, c);
	if (c == 'x')
		number = ft_itoa_base(nb, "0123456789abcdef");
	else if (c == 'X')
		number = ft_itoa_base(nb, "0123456789ABCDEF");
	if ((*flgs)->point && !((*flgs)->precision))
		(*flgs)->rtrn += 0;
	else
		(*flgs)->rtrn += ft_printstr(number);
	free(number);
	if ((*flgs)->wdth && (*flgs)->dash)
		(*flgs)->rtrn += right_padding((*flgs)->wdth - len);
}
