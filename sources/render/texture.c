/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:55:18 by Axel              #+#    #+#             */
/*   Updated: 2024/04/11 10:39:19 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	get_texture_index(t_ray *ray)
{
	if (ray->side)
	{
		if (ray->dir.x < 0)
			game()->text_info->index = WEST;
		else
			game()->text_info->index = EAST;
	}
	else
	{
		if (ray->dir.y < 0)
			game()->text_info->index = NORTH;
		else
			game()->text_info->index = SOUTH;
	}
}

void	update_texture_pixel(t_ray *ray, int curr_x)
{
	t_text_info	*text;
	int			y;
	int			color;

	text = game()->text_info;
	get_texture_index(ray);
	text->x = (int)(ray->wall_dist * text->size);
	text->step = text->size - text->x - 1;
	text->pos = (ray->start - (double)SCREEN_W / 2 + (double)ray->line_height / 2) * text->step;
	y = ray->start;
	while (y < ray->end)
	{
		text->y = (int)text->pos & (text->size - 1);
		text->pos += text->step;
		color = game()->textures[text->index][text->size * text->y + text->x];
		render_pixel((t_pos){curr_x, y}, color);
		y++;
	}
}
