/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_cam.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 05:16:39 by juchene           #+#    #+#             */
/*   Updated: 2023/08/17 17:10:23 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#define DEGREES_TO_RADIANS 0.017453

t_bool	parse_camera(t_scanner *scanner, t_scene *scene)
{
	int			fov;
	t_point		origin;
	t_vector	direction;
	t_camera	camera;

	if (!parse_position(scanner, &origin)
		|| !parse_direction(scanner, &direction)
		|| !parse_field_of_view(scanner, &fov)
		|| !scan_newline(scanner))
		return (FALSE);
	camera = new_camera(SCREEN_WIDTH, SCREEN_HEIGHT, fov * DEGREES_TO_RADIANS);
	camera.transform = view_transform(origin, point(0, 1, 0), direction);
	camera.inverse = inverse(camera.transform);
	scene->camera = camera;
	return (TRUE);
}
