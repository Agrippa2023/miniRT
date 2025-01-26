/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 12:45:52 by aouichou          #+#    #+#             */
/*   Updated: 2023/08/17 17:10:06 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_bool	match(t_scanner *scanner, char expected);
static t_bool	match_shape(t_scanner *scanner, char *expected);

t_token	parse_type(t_scanner *scanner)
{
	if (match(scanner, 'A'))
		return (TOKEN_AMBIENT_LIGHT);
	if (match(scanner, 'C'))
		return (TOKEN_CAMERA);
	if (match(scanner, 'L'))
		return (TOKEN_LIGHT);
	if (match_shape(scanner, "sp"))
		return (TOKEN_SPHERE);
	if (match_shape(scanner, "pl"))
		return (TOKEN_PLANE);
	if (match_shape(scanner, "cy"))
		return (TOKEN_CYLINDER);
	if (match_shape(scanner, "cn"))
		return (TOKEN_CONE);
	if (match(scanner, '#'))
		return (TOKEN_COMMENT);
	if (match(scanner, '\n'))
		return (TOKEN_NEWLINE);
	return (TOKEN_ERROR);
}

static t_bool	match(t_scanner *scanner, char expected)
{
	if (*scanner->current != expected)
		return (FALSE);
	advance(scanner);
	return (TRUE);
}

static t_bool	match_shape(t_scanner *scanner, char *expected)
{
	if (match(scanner, expected[0]))
	{
		if (match(scanner, expected[1]))
			return (TRUE);
		scanner->current--;
		return (FALSE);
	}
	return (FALSE);
}
