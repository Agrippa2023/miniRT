/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:04:54 by juchene           #+#    #+#             */
/*   Updated: 2023/08/17 17:09:10 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	advance(t_scanner *scanner)
{
	scanner->current++;
}

void	skip_whitespace(t_scanner *scanner)
{
	while (*scanner->current == ' ')
		advance(scanner);
	scanner->consume = scanner->current;
}

int	is_sign(int c)
{
	return (c == '-' || c == '+');
}

void	save_position(t_scanner *scanner)
{
	skip_whitespace(scanner);
	scanner->sync = scanner->consume;
}

void	sync_position(t_scanner *scanner)
{
	scanner->consume = scanner->sync;
}
