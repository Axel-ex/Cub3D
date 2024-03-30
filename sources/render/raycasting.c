/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 09:44:02 by Axel              #+#    #+#             */
/*   Updated: 2024/03/30 16:09:01 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	init_ray(t_ray *ray, int curr_x)
{
	double	x_cam;
	t_player	p;

	p = game()->player;
	x_cam = 2 * (double)curr_x / SCREEN_W - 1;
	ray->pos.x = p.pos.x;
	ray->pos.y = p.pos.y;
	ray->dir.x = p.dir.x + p.camera.x * x_cam;
	ray->dir.y = p.dir.y + p.camera.y * x_cam;
}

void	raycaster(void)
{
	t_ray	ray;
	int	x;

	x = -1;
	while (++x < SCREEN_W)
	{
		init_ray(&ray, x);
		// perform the algo
		// calculate th length of the ray
		// render the vertical stripe of pix on screen
		// render_ray on minimap
		render_line(to_screen_pos(ray.pos), ray.dir, 50, RED);
	}
}
