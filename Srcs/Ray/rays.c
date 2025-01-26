/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 03:38:56 by aouichou          #+#    #+#             */
/*   Updated: 2023/08/17 12:34:44 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shapes.h"

t_ray	new_ray(t_point origin, t_vector direction)
{
	return ((t_ray){
		origin, direction
	});
}

t_point	position(t_ray ray, float distance)
{
	return (add(ray.origin, multiply(ray.direction, distance)));
}

t_ray	transform(t_ray r, t_matrix m)
{
	return (
		new_ray(
			multiply_tp_mx(m, r.origin),
			multiply_tp_mx(m, r.direction))
	);
}
