/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 04:42:57 by aouichou          #+#    #+#             */
/*   Updated: 2023/08/17 13:12:44 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lights.h"

t_light	point_light(t_point position, t_color intensity)
{
	return ((t_light){
		.position = position,
		.intensity = intensity,
		.in_shadow = FALSE
	});
}
