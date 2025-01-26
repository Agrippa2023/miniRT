/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_cylinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 05:40:33 by juchene           #+#    #+#             */
/*   Updated: 2023/08/17 17:06:18 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

typedef struct s_param
{
	t_point		origin;
	t_vector	direction;
	double		diameter;
	double		height;
	float		radius;
	float		minimum;
	float		maximum;
}	t_param;

static void	set_cylinder_attributes(t_shape *shape, t_param param)
{
	t_matrix	scale;
	t_matrix	rotate;
	t_matrix	translate;

	shape->cylinder.closed = TRUE;
	shape->cylinder.radius = param.diameter / 2.0;
	shape->cylinder.maximum = param.height / 2.0;
	shape->cylinder.minimum = -param.height / 2.0;
	translate = translation(
			param.origin.x,
			param.origin.y,
			param.origin.z);
	scale = scaling(shape->cylinder.radius, 1, shape->cylinder.radius);
	rotate = rotation_matrix(param.direction);
	set_transform(shape,
		multiply_mx_mx(translate,
			multiply_mx_mx(rotate, scale)));
}

t_bool	parse_cylinder(t_scanner *scanner, t_scene *scene)
{
	t_param		param;
	t_shape		shape;

	shape = new_cylinder();
	if (!parse_position(scanner, &param.origin)
		|| !parse_direction(scanner, &param.direction)
		|| !parse_dimension(scanner, &param.diameter)
		|| !parse_dimension(scanner, &param.height)
		|| !parse_color(scanner, &shape.material.color)
		|| !parse_pattern(scanner, &shape)
		|| !scan_newline(scanner))
		return (FALSE);
	set_cylinder_attributes(&shape, param);
	add_object_to_world(&shape, &scene->world);
	return (TRUE);
}
