/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 10:39:30 by aouichou          #+#    #+#             */
/*   Updated: 2023/08/17 13:15:28 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shapes.h"

#define BIAS 0.0001
#define NODE_MAX 256

t_hit	*intersection(float t, t_shape *shape)
{
	static t_hit	pool[NODE_MAX];
	static size_t	node;
	t_hit			*hit;

	hit = pool + (node++ % NODE_MAX);
	hit->t = t;
	hit->object = shape;
	hit->next = NULL;
	return (hit);
}

t_bool	intersect(t_hit **xs, t_shape *shape, t_ray ray)
{
	t_ray	local_ray;

	local_ray = transform(ray, shape->inverse);
	shape->intersect(xs, shape, local_ray);
	return (TRUE);
}

void	insert_intersection(t_hit **xs, t_hit *isect)
{
	t_hit	*prev;
	t_hit	*curr;

	prev = NULL;
	curr = *xs;
	while (curr && curr->t < isect->t)
	{
		prev = curr;
		curr = curr->next;
	}
	if (prev == NULL)
	{
		isect->next = *xs;
		*xs = isect;
		return ;
	}
	prev->next = isect;
	isect->next = curr;
}

t_hit	*hit(t_hit *xs)
{
	while (xs != NULL && xs->t <= BIAS)
		xs = xs->next;
	return (xs);
}

int	intersection_count(t_hit *xs)
{
	int	count;

	count = 0;
	while (xs)
	{
		xs = xs->next;
		count++;
	}
	return (count);
}
