/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_utils_01.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 05:18:22 by juchene           #+#    #+#             */
/*   Updated: 2023/08/17 17:02:16 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// Fonction qui permet de parser un double
t_bool	parse_double(t_scanner *scanner, double *result)
{
	if (scan_double(scanner))
	{
		*result = ft_atof(scanner->consume);
		return (TRUE);
	}
	return (FALSE);
}

// Fonction qui permet de parser le ratio de la lumière
t_bool	parse_light_ratio(t_scanner *scanner, double *light)
{
	if (!scan_double(scanner))
		return (FALSE);
	*light = ft_atof(scanner->consume);
	if (validate_range(*light, 0, 1))
		return (TRUE);
	set_error_state(scanner, INVALID_LIGHT INVALID_NUMBER);
	return (FALSE);
}

// Fonction qui permet de parser la FOV
t_bool	parse_field_of_view(t_scanner *scanner, int *fov)
{
	if (!scan_integer(scanner))
		return (FALSE);
	*fov = ft_atoi(scanner->consume);
	if (validate_range(*fov, 0, 180))
		return (TRUE);
	set_error_state(scanner, INVALID_FOV INVALID_NUMBER);
	return (FALSE);
}

// Fonction qui permet de recuperer une dimension
t_bool	parse_dimension(t_scanner *scanner, double *dimension)
{
	if (!scan_double(scanner))
		return (FALSE);
	*dimension = ft_atof(scanner->consume);
	if (*dimension >= 0)
		return (TRUE);
	set_error_state(scanner, INVALID_DIMENSION INVALID_NUMBER);
	return (FALSE);
}

// Fonction qui permet de valider une valeur dans un intervalle
t_bool	validate_range(double value, double start, double end)
{
	if (value >= start && value <= end)
		return (TRUE);
	return (FALSE);
}
