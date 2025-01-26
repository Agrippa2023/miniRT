/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 07:13:42 by aouichou          #+#    #+#             */
/*   Updated: 2023/08/17 13:15:28 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"

void	init_mlx_connection(t_canvas *canvas)
{
	canvas->mlx_ptr = mlx_init();
	if (canvas->mlx_ptr)
		return ;
	ft_putendl_fd("Error: No X server found.", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

t_bool	new_canvas(t_canvas *canvas, int width, int height)
{
	canvas->mlx_ptr = mlx_init();
	if (!canvas->mlx_ptr)
		return (FALSE);
	canvas->width = width;
	canvas->height = height;
	canvas->img_ptr = mlx_new_image(canvas->mlx_ptr, width, height);
	if (!canvas->img_ptr)
		return (FALSE);
	canvas->addr = mlx_get_data_addr(canvas->img_ptr, &canvas->bpp,
			&canvas->line_len, &canvas->endian);
	if (!canvas->addr)
		return (FALSE);
	return (TRUE);
}

t_bool	put_on_window(t_canvas *canvas, char *title)
{
	canvas->win_ptr = mlx_new_window(canvas->mlx_ptr,
			canvas->width, canvas->height, title);
	if (!canvas->win_ptr)
	{
		free(canvas->win_ptr);
		return (FALSE);
	}
	return (TRUE);
}

int	show_window(t_canvas *canvas)
{
	mlx_put_image_to_window(canvas->mlx_ptr, canvas->win_ptr,
		canvas->img_ptr, 0, 0);
	return (EXIT_SUCCESS);
}
