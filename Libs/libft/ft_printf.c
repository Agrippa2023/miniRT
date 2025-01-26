/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:54:36 by aouichou          #+#    #+#             */
/*   Updated: 2022/06/03 17:24:41 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *str, ...)
{
	t_printf	*flgs;
	int			i;
	int			rtrn;

	rtrn = 0;
	flgs = (t_printf *)malloc(sizeof(t_printf));
	if (!flgs)
		return (-1);
	i = -1;
	flgs_init(flgs);
	va_start(flgs->args, str);
	while (str[++i])
	{
		if (str[i] == '%')
		{
			i = ft_print_arg(&flgs, (char *)str, i + 1);
			rtrn += flgs->rtrn;
			flgs_init(flgs);
		}
		else
			rtrn += ft_printchar(str[i]);
	}
	va_end(flgs->args);
	free(flgs);
	return (rtrn);
}
