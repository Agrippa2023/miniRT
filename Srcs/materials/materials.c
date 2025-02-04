/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   materials.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 12:35:59 by aouichou          #+#    #+#             */
/*   Updated: 2023/08/17 13:12:44 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "materials.h"
#include "shapes.h"

static t_color	dark_exposure(t_material m, t_exposure e);
static t_color	light_exposure(t_material m, t_light light, \
									t_exposure e, t_sight sight);

t_material	material(void)
{
	return ((t_material){
		.color = new_color(1, 1, 1),
		.ambient = new_color(0.1, 0.1, 0.1),
		.diffuse = 0.9,
		.specular = 0.9,
		.shininess = 200.0,
		.pattern.has_pattern = FALSE
	});
}

t_color	lighting(t_shape *shape, t_light light, t_point point, t_sight sight)
{
	t_exposure	e;
	t_color		color;

	if (shape->material.pattern.has_pattern)
		color = pattern_at_shape(shape->material.pattern, shape, point);
	else
		color = shape->material.color;
	e.effective_color = hadamard_product(color, light.intensity);
	e.lightv = normalize(subtract(light.position, point));
	e.light_dot_normal = dot(e.lightv, sight.normalv);
	if (e.light_dot_normal < 0 || light.in_shadow == TRUE)
		return (dark_exposure(shape->material, e));
	return (light_exposure(shape->material, light, e, sight));
}

static t_color	dark_exposure(t_material m, t_exposure e)
{
	t_color	ambient;
	t_color	diffuse;
	t_color	specular;

	ambient = hadamard_product(e.effective_color, m.ambient);
	diffuse = new_color(0, 0, 0);
	specular = new_color(0, 0, 0);
	return (add_color(add_color(ambient, diffuse), specular));
}

static t_color	light_exposure(t_material m, t_light light,
									t_exposure e, t_sight sight)
{
	t_color	ambient;
	t_color	diffuse;
	t_color	specular;

	ambient = hadamard_product(e.effective_color, m.ambient);
	diffuse = multiply_color(e.effective_color, m.diffuse * e.light_dot_normal);
	e.reflectv = reflect(negate(e.lightv), sight.normalv);
	e.reflect_dot_eye = dot(e.reflectv, sight.eyev);
	if (e.reflect_dot_eye <= 0)
		specular = new_color(0, 0, 0);
	else
	{
		e.factor = powf(e.reflect_dot_eye, m.shininess);
		specular = multiply_color(light.intensity, m.specular * e.factor);
	}
	return (add_color(add_color(ambient, diffuse), specular));
}
