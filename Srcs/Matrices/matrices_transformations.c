/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices_transformations.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 01:48:31 by aouichou          #+#    #+#             */
/*   Updated: 2023/08/17 14:43:10 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrices.h"

t_matrix	translation(double x, double y, double z)
{
	const double	transl[MAX][MAX] = {
	{1, 0, 0, x},
	{0, 1, 0, y},
	{0, 0, 1, z},
	{0, 0, 0, 1},
	};

	return (create_matrix(transl, MAX));
}

t_matrix	scaling(double x, double y, double z)
{
	const double	scale[MAX][MAX] = {
	{x, 0, 0, 0},
	{0, y, 0, 0},
	{0, 0, z, 0},
	{0, 0, 0, 1},
	};

	return (create_matrix(scale, MAX));
}

t_matrix	shearing(t_shearing x, t_shearing y, t_shearing z)
{
	const double	shear[MAX][MAX] = {
	{1, x.p1, x.p2, 0},
	{y.p1, 1, y.p2, 0},
	{z.p1, z.p2, 1, 0},
	{0, 0, 0, 1},
	};

	return (create_matrix(shear, MAX));
}
