/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:09:24 by Axel              #+#    #+#             */
/*   Updated: 2024/04/10 15:02:54 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	init_map(void)
{
	game()->map = ft_calloc(sizeof(t_map), 1);
	if (!game()->map)
		exit_error(ALLOC_ERROR, "map");
	game()->map->arr = NULL;
	game()->map->textures = ft_calloc(5, sizeof(int *));
	if (!game()->map->textures)
		exit_error(ALLOC_ERROR, "textures");
}

void	init_game(void)
{
	game()->map_info = ft_calloc(1, sizeof(t_map_info));
	if (!game()->map_info)
		exit_error(ALLOC_ERROR, "map_info");
	game()->map_info->arr= ft_calloc(1, sizeof(char *));
	if (!game()->map_info->arr)
		exit_error(ALLOC_ERROR, "map_info array");
	game()->map_info->no = NULL;
	game()->map_info->so = NULL;
	game()->map_info->we = NULL;
	game()->map_info->ea = NULL;
	game()->map_info->c = NULL;
	game()->map_info->f = NULL;
	game()->map_info->size = 0;
	init_map();
}

static void	init_mlx(void)
{
	game()->mlx = mlx_init();
	if (!game()->mlx)
		exit_error("mlx init", NULL);
	game()->mlx_win = mlx_new_window(game()->mlx, SCREEN_W, SCREEN_H, "cub3D");
	if (!game()->mlx_win)
		exit_error("mlx_win init", NULL);
	game()->screen_buff.img = mlx_new_image(game()->mlx, SCREEN_H, SCREEN_W);
	game()->screen_buff.addr = mlx_get_data_addr(game()->screen_buff.img,
			&game()->screen_buff.bbp, &game()->screen_buff.line_length,
			&game()->screen_buff.endian);
}

void	start_game(void)
{
	init_mlx();
	load_map();
	mlx_hook(game()->mlx_win, ON_KEYPRESS, KEYPRESS_MASK, key_press, NULL);
	mlx_hook(game()->mlx_win, ON_KEYRELEASE, KEYRELEASE_MASK, key_release, NULL);
	mlx_hook(game()->mlx_win, ON_DESTROY, DESTROY_MASK, quit_window, NULL);
	mlx_loop_hook(game()->mlx, render_frame, NULL);
	init_player();
	mlx_loop(game()->mlx);
}
