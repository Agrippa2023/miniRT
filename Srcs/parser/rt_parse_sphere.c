/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 05:35:57 by juchene           #+#    #+#             */
/*   Updated: 2023/08/17 16:36:30 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_bool	parse_sphere(t_scanner *scanner, t_scene *scene)
{
	t_shape		shape;
	t_matrix	scale;
	t_matrix	transform;
	t_point		origin;
	double		radius;

	shape = new_sphere();
	if (!parse_position(scanner, &origin)
		|| !parse_dimension(scanner, &radius)
		|| !parse_color(scanner, &shape.material.color)
		|| !parse_pattern(scanner, &shape)
		|| !scan_newline(scanner))
		return (FALSE);
	radius /= 2;
	scale = scaling(radius, radius, radius);
	transform = translation(origin.x, origin.y, origin.z);
	set_transform(&shape, multiply_mx_mx(transform, scale));
	add_object_to_world(&shape, &scene->world);
	return (TRUE);
}
