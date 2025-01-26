/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 07:13:08 by aouichou          #+#    #+#             */
/*   Updated: 2023/08/17 12:32:20 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"

int	quit(t_canvas *canvas)
{
	mlx_destroy_image(canvas->mlx_ptr, canvas->img_ptr);
	mlx_destroy_window(canvas->mlx_ptr, canvas->win_ptr);
	mlx_destroy_display(canvas->mlx_ptr);
	free(canvas->mlx_ptr);
	exit(EXIT_SUCCESS);
}

int	handle_keypress(int keysym, t_canvas *canvas)
{
	if (keysym == K_ESCAPE || keysym == K_Q)
		quit(canvas);
	return (EXIT_SUCCESS);
}
