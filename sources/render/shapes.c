/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:43:53 by Axel              #+#    #+#             */
/*   Updated: 2024/03/20 23:35:59 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	render_pixel(t_data *img, int x, int y, int color)
{
    char    *pixel;
    int		i;

    i = img->bits_per_pixel - 8;
    pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    while (i >= 0)
    {
        /* big endian, MSB is the leftmost bit */
        if (img->endian != 0)
            *pixel++ = (color >> i) & 0xFF;
        /* little endian, LSB is the leftmost bit */
        else
            *pixel++ = (color >> (img->bits_per_pixel - 8 - i)) & 0xFF;
        i -= 8;
    }
}

void	render_square(t_data *img, int x, int y, int width, int color)
{
	int	i;
	int	j;

	i = y;
	if ((x + width > SCREEN_W || x < 0) && (y + width > SCREEN_H || y < 0))
		return ;
	while (i < y + width)
	{
		j = x;
		while (j < x + width)
			my_mlx_pixel_put(img, j++, i, color);
		i++;
	}
	mlx_put_image_to_window(game()->mlx, game()->mlx_win, img->img, 0, 0);
}
