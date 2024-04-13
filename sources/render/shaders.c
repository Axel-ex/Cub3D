/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shaders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 22:53:48 by Axel              #+#    #+#             */
/*   Updated: 2024/04/13 20:14:23 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

// The idea behind these shaders is to attenuate the color passed by argument
// proprtionnally to the distance the object stands from the player. it is done
// linear interpolation (ex: if RENDER_DIST = 10, if the wall is 10 tiles away,
// the coef is equal to 0 so the resulting color is 0x00000000 (black)). each
// part that compose the color is attenuated by shifting with appropriate value
// and multiplying by the coef
int	shader(double wall_dist, int color)
{
	double	attenuation_coef;

	if (wall_dist > RENDER_DIST)
		return (BLACK);
	attenuation_coef = (RENDER_DIST - wall_dist) / RENDER_DIST;
	return (create_trgb(0, (int)(attenuation_coef * ((color >> 16) & 0xFF)),
		(int)(attenuation_coef * ((color >> 8) & 0xFF)),
		(int)(attenuation_coef * (color & 0xFF))));
}

int	shader_ceiling(int dist, int color)
{
	double	attenuation_coef;
	double	s;

	s = (double)SCREEN_H / 2;
	attenuation_coef = (s - dist) / s;
	return (create_trgb(0, (int)(attenuation_coef * ((color >> 16) & 0xFF)),
		(int)(attenuation_coef * ((color >> 8) & 0xFF)),
		(int)(attenuation_coef * (color & 0xFF))));
}

int	shader_floor(int dist, int color)
{
	double	attenuation_coef;
	double	s;

	s = (double)SCREEN_H / 2;
	attenuation_coef = (dist - s) / s;
	return (create_trgb(0, (int)(attenuation_coef * ((color >> 16) & 0xFF)),
		(int)(attenuation_coef * ((color >> 8) & 0xFF)),
		(int)(attenuation_coef * (color & 0xFF))));
}
