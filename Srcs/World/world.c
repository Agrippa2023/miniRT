/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 07:44:35 by aouichou          #+#    #+#             */
/*   Updated: 2023/08/17 13:03:00 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

t_hit	*intersect_world(t_world *world, t_ray ray)
{
	int		n;
	t_shape	*objects;

	n = 0;
	world->xs = NULL;
	objects = world->objects;
	while (n < world->object_count)
	{
		intersect(&world->xs, objects + n, ray);
		n++;
	}
	return (world->xs);
}

t_color	color_at(t_world world, t_ray ray)
{
	t_hit	*x;
	t_comps	comps;
	t_color	color;

	intersect_world(&world, ray);
	x = hit(world.xs);
	if (x == NULL)
		return (new_color(0, 0, 0));
	comps = prepare_computations(x, ray);
	color = shade_hit(world, comps);
	return (color);
}
