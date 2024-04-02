/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:49:34 by Axel              #+#    #+#             */
/*   Updated: 2024/04/02 18:53:33 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"
#include <stdlib.h>

static void	clear_screen_buffer(void)
{
	int	i;
	int	j;

	i = -1;
	while (++i < SCREEN_H)
	{
		j = -1;
		while (++j < SCREEN_W)
			render_pixel((t_pos){j, i}, BLACK);
	}
}

int	render_frame(void)
{
	if (game()->player.has_moved == false)
		return (EXIT_SUCCESS);
	clear_screen_buffer();
	raycaster();
	render_minimap();
	mlx_put_image_to_window(game()->mlx, game()->mlx_win,
		game()->screen_buff.img, 0, 0);
	game()->player.has_moved = false;
	return (EXIT_SUCCESS);
}

int	shader(double wall_dist, int color)
{
    double	attenuation_coef;
	int		red;
	int		green;
	int		blue;

	attenuation_coef = (RENDER_DIST - wall_dist) / RENDER_DIST;
    red = (int)(attenuation_coef * ((color >> 16) & 0xFF));
    green = (int)(attenuation_coef * ((color >> 8) & 0xFF));
    blue = (int)(attenuation_coef * (color & 0xFF));
	return (create_trgb(0, red, green, blue));
}

void	render_v_line(t_ray *ray, int x)
{
	int	i;
	int	color;
	
	if (ray->wall_dist > RENDER_DIST)
		return;
	if (ray->side)
		color = create_trgb(0, 200, 200, 0);
	else
		color = create_trgb(0, 100, 150, 0);
	color = shader(ray->wall_dist, color);
	i = ray->start - 1;
	while (++i < ray->end)
		render_pixel((t_pos){x, i}, color);
}

