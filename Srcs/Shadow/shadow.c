/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 05:30:24 by aouichou          #+#    #+#             */
/*   Updated: 2023/08/17 13:15:28 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

t_bool	is_shadowed(t_world *world, t_tuple point, int index)
{
	t_tuple	v;
	t_ray	r;
	t_hit	*intersections;
	t_hit	*h;

	v = subtract(world->lights[index].position, point);
	r = new_ray(point, normalize(v));
	intersections = intersect_world(world, r);
	h = hit(intersections);
	if (h && (h->t < magnitude(v)))
		return (TRUE);
	return (FALSE);
}

t_color	shade_hit(t_world world, t_comps comps)
{
	int		index;
	t_color	color;

	index = 0;
	color = new_color(0, 0, 0);
	while (index < world.light_count)
	{
		world.lights[index].in_shadow = is_shadowed(
				&world, comps.over_point, index);
		color = add_color(color,
				lighting(
					comps.object,
					world.lights[index],
					comps.point,
					comps.sight
					));
		index++;
	}
	return (color);
}
