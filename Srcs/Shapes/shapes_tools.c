/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 07:29:19 by aouichou          #+#    #+#             */
/*   Updated: 2023/08/17 12:56:10 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shapes.h"

t_shape	new_shape(void)
{
	return ((t_shape){
		.material = material(),
		.transform = get_identity_matrix(),
		.inverse = get_identity_matrix(),
		.transpose = get_identity_matrix(),
	});
}

void	set_transform(t_shape *shape, t_matrix transform)
{
	shape->transform = transform;
	shape->inverse = inverse(transform);
	shape->transpose = transpose(shape->inverse);
}

t_vector	normal_at(t_shape *shape, t_point world_point)
{
	t_point		object_point;
	t_vector	object_normal;
	t_vector	world_normal;

	object_point = multiply_tp_mx(shape->inverse, world_point);
	object_normal = shape->normal_at(shape, object_point);
	world_normal = multiply_tp_mx(shape->transpose, object_normal);
	world_normal.w = 0.0;
	return (normalize(world_normal));
}
