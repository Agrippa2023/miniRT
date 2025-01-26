/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 12:48:36 by aouichou          #+#    #+#             */
/*   Updated: 2023/08/17 13:15:28 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	init_scanner(t_scanner *scanner, const char *source)
{
	static int	line = 1;

	scanner->line = line++;
	scanner->start = source;
	scanner->consume = source;
	scanner->current = source;
	scanner->sync = source;
	scanner->message = ERROR_UNEXPECTED_ELEMENT;
}

t_bool	scan_integer(t_scanner *scanner)
{
	skip_whitespace(scanner);
	if (is_sign(*scanner->current))
		advance(scanner);
	if (!ft_isdigit(*scanner->current))
	{
		scanner->message = ERROR_EXPECTED_NUMBER;
		return (FALSE);
	}
	while (ft_isdigit(*scanner->current))
		advance(scanner);
	return (TRUE);
}

t_bool	scan_double(t_scanner *scanner)
{
	if (!scan_integer(scanner))
		return (FALSE);
	if (*scanner->current == '.')
	{
		advance(scanner);
		while (ft_isdigit(*scanner->current))
			advance(scanner);
	}
	return (TRUE);
}

t_bool	scan_comma(t_scanner *scanner)
{
	skip_whitespace(scanner);
	if (*scanner->current == ',')
	{
		advance(scanner);
		return (TRUE);
	}
	scanner->message = ERROR_EXPECTED_COMMA;
	return (FALSE);
}

t_bool	scan_newline(t_scanner *scanner)
{
	skip_whitespace(scanner);
	if (*scanner->current == '\n')
		return (TRUE);
	scanner->message = ERROR_EXPECTED_NEWLINE;
	return (FALSE);
}
