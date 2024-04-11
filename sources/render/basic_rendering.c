/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_rendering.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:43:53 by Axel              #+#    #+#             */
/*   Updated: 2024/04/11 11:55:41 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	render_pixel(t_pos pos, int color)
{
	char	*dst;
	t_img	img;

	img = game()->screen_buff;
	dst = (char *)img.addr + ((int)pos.y * img.line_length + (int)pos.x * (img.bbp / 8));
	*(unsigned int *)dst = color;
}

void	render_square(t_square square)
{
	int	i;
	int	j;

	i = square.pos.y;
	if ((square.pos.x + square.width > SCREEN_W || square.pos.x < 0) && (square.pos.y
			+ square.width > SCREEN_H || square.pos.y < 0))
		return ;
	while (i < square.pos.y + square.width)
	{
		j = square.pos.x;
		while (j < square.pos.x + square.width)
			render_pixel((t_pos){j++, i}, square.color);
		i++;
	}
}

void	render_line(t_pos start, t_pos dir, int length, int color)
{
	int	i;

	i = -1;
	while (++i < length)
	{
		render_pixel(add_pos(start, dir), color);
		start.x += dir.x;
		start.y += dir.y;
	}
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
