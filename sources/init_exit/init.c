/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:09:24 by Axel              #+#    #+#             */
/*   Updated: 2024/03/20 23:26:07 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	init_game(void)
{
	ft_bzero(game(), sizeof(t_game));
	game()->mlx = mlx_init();
	game()->pixel = (t_data *)malloc(sizeof(t_data));
	game()->mlx_win = mlx_new_window(game()->mlx, SCREEN_W, SCREEN_H, "cub3D");
	game()->pixel->img = mlx_new_image(game()->mlx, SCREEN_H, SCREEN_W);
	game()->pixel->addr = mlx_get_data_addr(game()->pixel->img,
			&game()->pixel->bits_per_pixel, &game()->pixel->line_length,
			&game()->pixel->bits_per_pixel);
}
