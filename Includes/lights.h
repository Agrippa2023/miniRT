/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 12:22:31 by aouichou          #+#    #+#             */
/*   Updated: 2023/08/17 13:15:44 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// @file lights.h
#ifndef LIGHTS_H
# define LIGHTS_H

# include "tuples.h"
# include "libft.h"

/**
 * ABOUT THE HEADER LIGHTS.H
 *
 * The light algorithm implemented on this project is called The Phong
 * Reflection Model, named by its creator Bui Tuong Phong. It simulates
 * the interaction between three light sources. They are: ambient reflection,
 * diffuse reflection and specular reflection. In other words, respectively,
 * background light, the light reflected from a matte surface and the
 * reflection of the source light itself. The last one, depends only on the
 * angle between the reflection vector and the eye vector and is controlled
 * by a parameter that's called shininess. The higher the shininess, the
 * smaller and tigher the specular highlight is.
 */

/**
 * @brief The struct s_light represents a light's source. This source has
 *        a position in space and an intensity color, i.e., red, purple etc.
 * @param position Stores the point light's position.
 * @param intensity Stores the information about how bright a point light is.
 * @param in_shadow Stores `TRUE` or `FALSE` whether the light is being
 *                  shadowed or not.
 */
typedef struct s_light
{
	t_point	position;
	t_color	intensity;
	t_bool	in_shadow;
}	t_light;

/**
 * @brief The struct s_sight represents the human eye looking forwards.
 *
 * For the Phong Reflection Model algorithm, this human sight has an
 * eye vision, which is the direction where the eyes are looking at and
 * it also has a normal vision, i.e., the perpendicular vector from where
 * the eye vision is looking at.
 * 
 * @param eyev Represents the eye's vector looking at something.
 * @param normalv Represents the normal vector of some surface.
 */
typedef struct s_sight
{
	t_vector	eyev;
	t_vector	normalv;
}	t_sight;

/* ************************************************************************** */
/*                                 LIGHTS.C                                   */
/* ************************************************************************** */

/**
 * @brief The function point_light() instances a light's source of type
 *        t_light with a given position in space and a light color intensity.
 *
 * @param position A struct of type t_tuple storing the light's source
 *                 location in space.
 * @param intensity A struct of type t_color containing the light's source
 *                  color intensity.
 * @return Returns a light's source with a given location in space and a color
 *         intensity in RGB values.
 */

t_light	point_light(t_point position, t_color intensity);

#endif
