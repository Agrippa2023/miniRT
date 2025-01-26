/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 07:25:04 by aouichou          #+#    #+#             */
/*   Updated: 2023/08/17 13:15:28 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrices.h"

t_shearing	to_shear(double p1, double p2)
{
	return ((t_shearing){p1, p2});
}

t_matrix	create_matrix(const double table[MAX][MAX], size_t size)
{
	t_matrix	m;

	m.size = size;
	ft_memmove(m.matrix, table, sizeof(double) * SIZE);
	return (m);
}

int	compare_matrix(t_matrix a, t_matrix b)
{
	return (ft_memcmp(a.matrix, b.matrix, sizeof(double) * SIZE));
}

t_bool	is_invertible(t_matrix t)
{
	if (get_determinant(t) == 0)
		return (FALSE);
	return (TRUE);
}
