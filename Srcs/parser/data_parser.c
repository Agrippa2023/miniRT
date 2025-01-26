/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:28:58 by juchene           #+#    #+#             */
/*   Updated: 2023/08/17 17:09:41 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_bool	parse_comment(t_scanner *scanner)
{
	while (*scanner->current != '\n')
		advance(scanner);
	if (!scan_newline(scanner))
		return (FALSE);
	return (TRUE);
}

static void	*expand(void *ptr, size_t old_size, size_t element_size)
{
	size_t	new_size;
	void	*new_ptr;

	new_size = old_size + 1;
	new_ptr = malloc(new_size * element_size);
	if (new_ptr == NULL)
		return (NULL);
	if (ptr != NULL)
	{
		ft_memcpy(new_ptr, ptr, old_size * element_size);
		free(ptr);
	}
	return (new_ptr);
}

void	add_object_to_world(t_shape *shape, t_world *world)
{
	world->objects = expand(
			world->objects, world->object_count, sizeof(t_shape));
	world->objects[world->object_count++] = *shape;
}

void	add_light_to_world(t_light *light, t_world *world)
{
	world->lights = expand(world->lights, world->light_count, sizeof(t_light));
	world->lights[world->light_count++] = *light;
}

t_bool	parse_element(t_scanner *scanner, t_scene *scene, int totals[])
{
	t_token	type;

	type = parse_type(scanner);
	totals[type]++;
	if (type == TOKEN_AMBIENT_LIGHT)
		return (parse_ambient_light(scanner, scene));
	if (type == TOKEN_CAMERA)
		return (parse_camera(scanner, scene));
	if (type == TOKEN_LIGHT)
		return (parse_light(scanner, scene));
	if (type == TOKEN_SPHERE)
		return (parse_sphere(scanner, scene));
	if (type == TOKEN_PLANE)
		return (parse_plane(scanner, scene));
	if (type == TOKEN_CYLINDER)
		return (parse_cylinder(scanner, scene));
	if (type == TOKEN_CONE)
		return (parse_cone(scanner, scene));
	if (type == TOKEN_COMMENT)
		return (parse_comment(scanner));
	if (type == TOKEN_NEWLINE)
		return (TRUE);
	return (FALSE);
}
