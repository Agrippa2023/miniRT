/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 03:20:03 by aouichou          #+#    #+#             */
/*   Updated: 2022/06/03 17:24:03 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_c(char c, t_printf **flgs)
{
	if ((*flgs)->wdth && !(*flgs)->dash)
		(*flgs)->rtrn += left_padding((*flgs)->wdth - 1, 1);
	(*flgs)->rtrn += ft_printchar(c);
	if ((*flgs)->wdth && (*flgs)->dash)
		(*flgs)->rtrn += right_padding((*flgs)->wdth - 1);
}

void	ft_print_s_precision(char *str, t_printf **flgs, int len)
{
	char	*string;

	if ((*flgs)->point && (*flgs)->precision < len)
	{
		string = ft_strnew((*flgs)->precision + 1);
		ft_strlcat(string, str, (*flgs)->precision + 1);
		(*flgs)->rtrn += ft_printstr(string);
		free(string);
	}
	else
		(*flgs)->rtrn += ft_printstr(str);
}

void	ft_print_null(t_printf **flgs)
{
	int		len;
	char	*str;

	str = "(null)";
	len = ft_strlen(str);
	if ((*flgs)->point && (*flgs)->precision < len)
	{
		str = "";
		len = 0;
	}
	if ((*flgs)->wdth && !(*flgs)->dash)
		(*flgs)->rtrn += left_padding((*flgs)->wdth - len, 1);
	(*flgs)->rtrn += ft_printstr(str);
	if ((*flgs)->wdth && (*flgs)->dash)
		(*flgs)->rtrn += right_padding((*flgs)->wdth - len);
}

void	ft_print_s(char *str, t_printf **flgs)
{
	int		len;

	if (!str)
	{
		ft_print_null(flgs);
		return ;
	}
	len = ft_strlen(str);
	if ((*flgs)->wdth && !(*flgs)->dash)
	{
		if ((*flgs)->point && len > (*flgs)->precision)
			(*flgs)->rtrn += left_padding((*flgs)->wdth
					- (*flgs)->precision, 1);
		else
			(*flgs)->rtrn += left_padding((*flgs)->wdth - len, 1);
	}
	ft_print_s_precision(str, flgs, len);
	if ((*flgs)->wdth && (*flgs)->dash)
	{
		if ((*flgs)->point && len > (*flgs)->precision)
			(*flgs)->rtrn += right_padding((*flgs)->wdth - (*flgs)->precision);
		else
			(*flgs)->rtrn += right_padding((*flgs)->wdth - len);
	}
}
