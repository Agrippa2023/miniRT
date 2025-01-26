/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:34:17 by aouichou          #+#    #+#             */
/*   Updated: 2023/08/17 14:44:37 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

t_comps	prepare_computations(t_hit *intersection, t_ray ray)
{
	t_comps	comps;

	comps.t = intersection->t;
	comps.object = intersection->object;
	comps.point = position(ray, comps.t);
	comps.sight.eyev = negate(ray.direction);
	comps.sight.normalv = normal_at(comps.object, comps.point);
	comps.inside = FALSE;
	if (dot(comps.sight.normalv, comps.sight.eyev) < 0)
	{
		comps.inside = TRUE;
		comps.sight.normalv = negate(comps.sight.normalv);
	}
	comps.over_point = add(comps.point, multiply(comps.sight.normalv, EPSILON));
	return (comps);
}
