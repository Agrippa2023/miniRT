/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 12:46:24 by aouichou          #+#    #+#             */
/*   Updated: 2023/08/17 17:09:23 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#define RED "\033[31;1m"
#define BOLD "\033[1m"
#define RESET "\033[m"

void	set_error_state(t_scanner *scanner, const char *error_message)
{
	scanner->message = error_message;
	scanner->current = scanner->consume;
}

void	display_position(t_scanner *scanner, int line, int column)
{
	ft_printf("%5d | %s%5s | ", line, scanner->start, " ");
	while (--column > 0)
		ft_printf(" ");
	ft_printf(RED"^\n"RESET);
}

int	get_error_column(t_scanner *scanner)
{
	return (scanner->current - scanner->start);
}

t_bool	report_error(t_scanner *scanner)
{
	int		line;
	int		column;
	char	*position;

	line = scanner->line;
	column = get_error_column(scanner) + 1;
	position = BOLD"%s at line %d, column %d:\n"RESET;
	ft_putendl_fd("Error", STDOUT_FILENO);
	ft_printf(position, scanner->message, line, column);
	display_position(scanner, line, column);
	return (FALSE);
}
