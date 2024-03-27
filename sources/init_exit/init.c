/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:09:24 by Axel              #+#    #+#             */
/*   Updated: 2024/03/27 18:07:34 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

char		*map[5] = {"111111111111", "100000000N01", "100000000001",
			"111111111111", NULL};

static void	init_mlx(void)
{
	game()->mlx = mlx_init();
	if (!game()->mlx)
		exit_error("mlx init", MALLOC_ERROR);
	game()->mlx_win = mlx_new_window(game()->mlx, SCREEN_W, SCREEN_H, "cub3D");
	if (!game()->mlx_win)
		exit_error("mlx_win init", MALLOC_ERROR);
	game()->screen_buff.img = mlx_new_image(game()->mlx, SCREEN_H, SCREEN_W);
	game()->screen_buff.addr = mlx_get_data_addr(game()->screen_buff.img,
			&game()->screen_buff.bbp, &game()->screen_buff.line_length,
			&game()->screen_buff.endian);
	game()->map = malloc(sizeof(t_map));
	game()->map->arr= NULL;
	game()->map->no = NULL;
	game()->map->so = NULL;
	game()->map->we = NULL;
	game()->map->ea = NULL;
	game()->map->c = NULL;
	game()->map->f = NULL;
}

