/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:43:53 by Axel              #+#    #+#             */
/*   Updated: 2024/03/21 08:39:55 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	render_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bbp / 8));
	*(unsigned int *)dst = color;
}

void	render_square(t_img *img, t_square square)
{
	int	i;
	int	j;

	i = square.y;
	if ((square.x + square.width > SCREEN_W || square.x < 0) && (square.y + square.width > SCREEN_H || square.y < 0))
		return ;
	while (i < square.y + square.width)
	{
		j = square.x;
		while (j < square.x + square.width)
			render_pixel(img, j++, i, square.color);
		i++;
	}
	mlx_put_image_to_window(game()->mlx, game()->mlx_win, img->img, 0, 0);
}
