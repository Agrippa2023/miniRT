/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:23:45 by juchene           #+#    #+#             */
/*   Updated: 2023/08/17 17:11:04 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "patterns.h"

static t_bool	set_filename(t_scanner *scanner, char *texture_file);
static t_bool	load_bumpmap(t_shape *shape, char *texture_file);

t_bool	parse_texture(t_scanner *scanner, t_shape *shape)
{
	char	texture_file[BUFFER];

	skip_whitespace(scanner);
	set_error_state(scanner, INVALID_FILE);
	if (!set_filename(scanner, texture_file))
		return (FALSE);
	if (!load_bumpmap(shape, texture_file))
		return (FALSE);
	return (TRUE);
}

static t_bool	load_bumpmap(t_shape *shape, char *texture_file)
{
	t_uv_image	*bumpmap;
	t_pattern	pattern;

	bumpmap = malloc(sizeof(t_uv_image));
	if (!bumpmap)
		return (FALSE);
	bumpmap->mlx_ptr = mlx_init();
	bumpmap->img_ptr = mlx_xpm_file_to_image(bumpmap->mlx_ptr, texture_file,
			&bumpmap->width, &bumpmap->height);
	if (!bumpmap->img_ptr)
		return (FALSE);
	bumpmap->addr = mlx_get_data_addr(bumpmap->img_ptr, &bumpmap->bpp,
			&bumpmap->line_len, &bumpmap->endian);
	pattern = new_pattern(new_color(0, 0, 0), new_color(1, 1, 1));
	pattern.texture_map.canvas = bumpmap;
	pattern.pattern_at = bumped_at;
	shape->material.pattern = pattern;
	shape->material.specular = 0;
	texture_map(&shape->material.pattern, shape->checker, shape->map);
	return (TRUE);
}

static t_bool	set_filename(t_scanner *scanner, char *texture_file)
{
	char	*end;
	int		length;

	end = ft_strchr(scanner->current, ' ');
	if (!end)
		end = ft_strchr(scanner->current, '\n');
	length = end - scanner->consume;
	ft_strlcpy(texture_file, scanner->consume, length + 1);
	if (access(texture_file, F_OK) != 0)
		return (FALSE);
	if (!check_extension(texture_file, "xpm"))
		return (FALSE);
	scanner->current += length;
	return (TRUE);
}
