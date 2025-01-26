/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 09:05:44 by aouichou          #+#    #+#             */
/*   Updated: 2023/08/17 14:42:46 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "rays.h"
#include "tuples.h"

static void	set_pixel_size(t_camera *camera)
{
	float	half_view;
	float	aspect;

	half_view = tanf(camera->field_of_view / 2);
	aspect = camera->hsize / camera->vsize;
	if (aspect >= 1)
	{
		camera->half_width = half_view;
		camera->half_height = half_view / aspect;
	}
	else
	{
		camera->half_width = half_view * aspect;
		camera->half_height = half_view;
	}
	camera->pixel_size = (camera->half_width * 2) / camera->hsize;
}

t_camera	new_camera(float hsize, float vsize, float field_of_view)
{
	t_camera	camera;

	camera.hsize = hsize;
	camera.vsize = vsize;
	camera.field_of_view = field_of_view;
	camera.transform = get_identity_matrix();
	camera.inverse = inverse(camera.transform);
	set_pixel_size(&camera);
	return (camera);
}

t_ray	ray_for_pixel(t_camera *camera, float px, float py)
{
	float		world_x;
	float		world_y;
	t_point		pixel;
	t_point		origin;
	t_vector	direction;

	world_x = camera->half_width - (px + 0.5) * camera->pixel_size;
	world_y = camera->half_height - (py + 0.5) * camera->pixel_size;
	pixel = multiply_tp_mx(camera->inverse, point(world_x, world_y, -1));
	origin = multiply_tp_mx(camera->inverse, point(0, 0, 0));
	direction = normalize(subtract(pixel, origin));
	return (new_ray(origin, direction));
}

static t_matrix	orient_xform(t_vector forward, t_vector left, t_vector true_up)
{
	const double	table[MAX][MAX] = {
	{left.x, left.y, left.z, 0},
	{true_up.x, true_up.y, true_up.z, 0},
	{-forward.x, -forward.y, -forward.z, 0},
	{0, 0, 0, 1},
	};

	return (create_matrix(table, MAX));
}

static t_matrix	orient_xform(t_vector forward, t_vector left, t_vector true_up);

t_matrix	view_transform(t_point from, t_point to, t_vector up)
{
	t_point		forward;
	t_point		left;
	t_vector	true_up;
	t_matrix	orientation;

	forward = normalize(subtract(to, from));
	left = cross(forward, normalize(up));
	true_up = cross(left, forward);
	orientation = orient_xform(forward, left, true_up);
	return (multiply_mx_mx(
			orientation,
			translation(-from.x, -from.y, -from.z))
	);
}
