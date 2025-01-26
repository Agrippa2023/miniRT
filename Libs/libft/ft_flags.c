/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 02:46:39 by aouichou          #+#    #+#             */
/*   Updated: 2022/06/03 17:23:46 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	set_flag(t_printf **flgs, char c)
{
	if (c == '0')
		(*flgs)->zero = 1;
	if (c == '.')
		(*flgs)->point = 1;
	if (c == '-')
		(*flgs)->dash = 1;
	if (c == '+')
		(*flgs)->sign = 1;
	if (c == ' ')
		(*flgs)->space = 1;
	if (c == '#')
		(*flgs)->hash = 1;
}

int	ft_eval_str(t_printf **flgs, char *str, int i)
{
	while (!(is_specifier(str[i])))
	{
		set_flag(flgs, str[i]);
		if (ft_isdigit(str[i]) && (*flgs)->point)
			(*flgs)->precision = ft_atoi(str + i);
		else if (ft_isdigit(str[i]))
			(*flgs)->wdth = ft_atoi(str + i);
		while (ft_isdigit(str[i]) && ft_isdigit(str[i + 1]))
			i++;
		i++;
	}
	if ((*flgs)->dash || (*flgs)->point)
		(*flgs)->zero = 0;
	return (i);
}

int	ft_print_arg(t_printf **flgs, char *str, int i)
{
	i = ft_eval_str(flgs, str, i);
	if (str[i] == 'c')
		ft_print_c(va_arg((*flgs)->args, int), flgs);
	else if (str[i] == 's')
		ft_print_s(va_arg((*flgs)->args, char *), flgs);
	else if (str[i] == 'p')
		ft_print_p(va_arg((*flgs)->args, void *), flgs);
	else if (str[i] == 'd' || str[i] == 'i')
		ft_print_d_i(va_arg((*flgs)->args, int), flgs);
	else if (str[i] == 'u')
		ft_print_u(va_arg((*flgs)->args, unsigned int), flgs);
	else if (str[i] == 'x' || str[i] == 'X')
		ft_print_x(va_arg((*flgs)->args, unsigned int), flgs, str[i]);
	else if (str[i] == '%')
	{
		(*flgs)->wdth = 0;
		ft_print_c('%', flgs);
	}
	return (i);
}
