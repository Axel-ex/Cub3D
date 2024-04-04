/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:49:34 by Axel              #+#    #+#             */
/*   Updated: 2024/04/03 12:38:37 by achabrer         ###   ########.fr       */
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

static void	render_ceiling(void)
{
	int	i;
	int	j;

	i = -1;
	while (++i < SCREEN_H / 2)
	{
		j = -1;
		while (++j < SCREEN_W)
			render_pixel((t_pos){j, i}, shader_ceiling(i, game()->map->ceiling_col));
	}
}

static void	render_floor(void)
{
	int	i;
	int	j;

	i = SCREEN_H / 2 - 1;
	while (++i < SCREEN_H)
	{
		j = -1;
		while (++j < SCREEN_W)
			render_pixel((t_pos){j, i}, shader_floor(i, game()->map->floor_col));
	}
}

int	render_frame(void)
{
	if (game()->player.has_moved == false)
		return (EXIT_SUCCESS);
	clear_screen_buffer();
	render_ceiling();
	render_floor();
	raycaster();
	if (game()->map->render_map)
		render_minimap();
	mlx_put_image_to_window(game()->mlx, game()->mlx_win,
		game()->screen_buff.img, 0, 0);
	game()->player.has_moved = false;
	game()->map->render_map = false;
	return (EXIT_SUCCESS);
}
