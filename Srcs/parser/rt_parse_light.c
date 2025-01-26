/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 05:28:09 by juchene           #+#    #+#             */
/*   Updated: 2023/08/17 17:02:05 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_bool	parse_light(t_scanner *scanner, t_scene *scene)
{
	t_point	origin;
	double	bright;
	t_color	color;
	t_light	light;

	if (!parse_position(scanner, &origin)
		|| !parse_light_ratio(scanner, &bright)
		|| !parse_color(scanner, &color)
		|| !scan_newline(scanner))
		return (FALSE);
	color = multiply_color(color, bright);
	light = point_light(origin, color);
	add_light_to_world(&light, &scene->world);
	return (TRUE);
}

t_bool	parse_ambient_light(t_scanner *scanner, t_scene *scene)
{
	double	intensity;
	t_color	lighting;

	if (!parse_light_ratio(scanner, &intensity)
		|| !parse_color(scanner, &lighting)
		|| !scan_newline(scanner))
		return (FALSE);
	scene->world.ambient = multiply_color(lighting, intensity);
	return (TRUE);
}
