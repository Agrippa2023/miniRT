/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices_ops2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 07:31:37 by aouichou          #+#    #+#             */
/*   Updated: 2023/08/17 12:37:36 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrices.h"
#include "tuples.h"

t_matrix	multiply_mx_mx(t_matrix a, t_matrix b)
{
	double		m[MAX][MAX];
	size_t		row;
	size_t		col;

	ft_bzero(m, sizeof(double) * SIZE);
	row = -1;
	while (++row < MAX)
	{
		col = -1;
		while (++col < MAX)
		{
			m[row][col] = a.matrix[row][0] * b.matrix[0][col]
				+ a.matrix[row][1] * b.matrix[1][col]
				+ a.matrix[row][2] * b.matrix[2][col]
				+ a.matrix[row][3] * b.matrix[3][col];
		}
	}
	return (create_matrix(m, MAX));
}

t_tuple	multiply_tp_mx(t_matrix a, t_tuple b)
{
	double		t[MAX];
	size_t		row;

	row = -1;
	while (++row < MAX)
	{
		t[row] = a.matrix[row][0] * b.x \
			+ a.matrix[row][1] * b.y \
			+ a.matrix[row][2] * b.z \
			+ a.matrix[row][3] * b.w;
	}
	return (tuple(t[0], t[1], t[2], t[3]));
}

t_matrix	transpose(t_matrix	t)
{
	size_t		row;
	size_t		col;
	double		m[MAX][MAX];

	row = -1;
	while (++row < t.size)
	{
		col = -1;
		while (++col < t.size)
			m[col][row] = t.matrix[row][col];
	}
	return (create_matrix(m, t.size));
}

t_matrix	inverse(t_matrix t)
{
	double	inverted[MAX][MAX];
	double	determinant;	
	size_t	row;
	size_t	col;

	if (!is_invertible(t))
		return (get_identity_matrix());
	determinant = get_determinant(t);
	row = -1;
	while (++row < t.size)
	{
		col = -1;
		while (++col < t.size)
			inverted[col][row] = \
				get_cofactor(t, row, col) / determinant;
	}
	return (create_matrix(inverted, MAX));
}
