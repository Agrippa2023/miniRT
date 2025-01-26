/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:23:22 by aouichou          #+#    #+#             */
/*   Updated: 2023/08/17 13:00:19 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

t_tuple	add(t_tuple a, t_tuple b)
{
	return ((t_tuple){
		a.x + b.x,
		a.y + b.y,
		a.z + b.z,
		a.w + b.w,
	});
}

t_tuple	subtract(t_tuple a, t_tuple b)
{
	return ((t_tuple){
		a.x - b.x,
		a.y - b.y,
		a.z - b.z,
		a.w - b.w,
	});
}

t_tuple	negate(t_tuple a)
{
	return ((t_tuple){
		a.x * -1,
		a.y * -1,
		a.z * -1,
		a.w * -1,
	});
}

t_tuple	multiply(t_tuple a, double scalar)
{
	return ((t_tuple){
		a.x * scalar,
		a.y * scalar,
		a.z * scalar,
		a.w * scalar,
	});
}

t_tuple	divide(t_tuple a, double scalar)
{
	return ((t_tuple){
		a.x / scalar,
		a.y / scalar,
		a.z / scalar,
		a.w / scalar,
	});
}
