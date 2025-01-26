/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_plane.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 05:37:16 by juchene           #+#    #+#             */
/*   Updated: 2023/08/17 16:37:17 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_bool	parse_plane(t_scanner *scanner, t_scene *scene)
{
	t_shape		shape;
	t_vector	direction;
	t_point		origin;
	t_matrix	translate;
	t_matrix	rotate;

	shape = new_plane();
	if (!parse_position(scanner, &origin)
		|| !parse_direction(scanner, &direction)
		|| !parse_color(scanner, &shape.material.color)
		|| !parse_pattern(scanner, &shape)
		|| !scan_newline(scanner))
		return (FALSE);
	translate = translation(origin.x, origin.y, origin.z);
	rotate = rotation_matrix(direction);
	set_transform(&shape, multiply_mx_mx(translate, rotate));
	add_object_to_world(&shape, &scene->world);
	return (TRUE);
}
